#include <vector>
#include <tuple>
#include <algorithm>
#include "../1Dquery/BIT.cpp"

template<typename Val = long long, typename Idx = int>
struct point_add_rectangle_sum{
private:
  int M = 1;
  std::vector<Idx> X;
  std::vector<std::vector<Idx>> Y;
  std::vector<BIT<Val>> BITs;
  using point = std::tuple<Idx, Idx, Val>;
public:
  point_add_rectangle_sum(){}
  point_add_rectangle_sum(std::vector<point> v){
    int n = v.size();
    std::sort(v.begin(), v.end(), [](const point &a, const point &b){return std::get<1>(a) < std::get<1>(b);});
    for(int i=0;i<n;i++) X.push_back(std::get<0>(v[i]));
    std::sort(X.begin(), X.end());
    X.erase(std::unique(X.begin(), X.end()), X.end());
    M = (int)X.size();
    std::vector<std::vector<Val>> tmp(M+1);
    BITs.resize(M+1);
    Y.resize(M+1);
    for(int i=0;i<n;i++){
      auto [x, y, z] = v[i];
      int k = lower_bound(X.begin(), X.end(), x) - X.begin();
      for(int j=k+1;j<=M;j+=(j&(-j))){
        if(Y[j].empty()||Y[j].back()!=y){
          Y[j].push_back(y);
          tmp[j].push_back(z);
        }else{
          tmp[j].back() += z;
        }
      }
    }
    for(int i=0;i<=M;i++) BITs[i] = BIT(tmp[i]);
  }
  void add(Idx x, Idx y, Val z){
    auto xidx = lower_bound(X.begin(), X.end(), x) - X.begin();
    for(int i=xidx+1;i<=M;i+=(i&(-i))){
      auto yidx = lower_bound(Y[i].begin(), Y[i].end(), y) - Y[i].begin();
      BITs[i].add(yidx, z);
    }
  }
  Val getsum(int rx, Idx ly, Idx ry){
    Val ret = 0;
    for(int i=rx;i>0;i-=(i&(-i))){
      int right = std::lower_bound(Y[i].begin(), Y[i].end(), ry) - Y[i].begin();
      int left = std::lower_bound(Y[i].begin(), Y[i].end(), ly) - Y[i].begin();
      ret += BITs[i].getsum(left, right);
    }
    return ret;
  }
  Val getsum(Idx lx, Idx rx, Idx ly, Idx ry){
    Val right = getsum(std::lower_bound(X.begin(), X.end(), rx)-X.begin(), ly, ry);
    Val left = getsum(std::lower_bound(X.begin(), X.end(), lx)-X.begin(), ly, ry);
    return right - left;
  }
};
