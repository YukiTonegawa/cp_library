#include <vector>
#include <tuple>
#include <array>
#include <algorithm>
#include "../1Dquery/BIT.cpp"

template<typename Val = long long, typename Idx = int>
struct point_add_rectangle_sum{
private:
  using query = std::tuple<int, Idx, Idx, Idx, Idx, Val>;//index, x, ly, ry, value
  using query2 = std::tuple<Idx, int, int, int, int, Val>;//x, query_type, index, ly, ry, value
  std::vector<query> q;
  std::vector<int> question{0};
  int qs = 0;
  void solve(int l, int r, std::vector<Val> &ans){
    if(r - l < 2) return;
    int mid = (l + r) >> 1;
    solve(l, mid, ans);
    solve(mid, r, ans);
    int left_insert = (mid - l) - (question[mid] - question[l]);
    int right_question = question[r] - question[mid];
    if(left_insert == 0 || right_question == 0) return;
    std::vector<Idx> y;
    for(int i=l;i<mid;i++) if(std::get<0>(q[i]) == -1) y.push_back(std::get<3>(q[i]));
    std::sort(y.begin(), y.end());
    y.erase(std::unique(y.begin(), y.end()), y.end());
    BIT<Val> bit(y.size());
    std::vector<query2> tmp_q;
    for(int i=l;i<mid;i++){
      if(std::get<0>(q[i]) == -1){
        auto [idx, lx, rx, ly, ry, val] = q[i];
        int y_idx = lower_bound(y.begin(), y.end(), ly) - y.begin();
        tmp_q.push_back(std::make_tuple(lx, 2, -1, y_idx, 0, val));
      }
    }
    for(int i=mid;i<r;i++){
      if(std::get<0>(q[i]) != -1){
        auto [idx, lx, rx, ly, ry, val] = q[i];
        int ly_idx = lower_bound(y.begin(), y.end(), ly) - y.begin();
        int ry_idx = lower_bound(y.begin(), y.end(), ry) - y.begin();
        tmp_q.push_back(std::make_tuple(lx, 0, idx, ly_idx, ry_idx, 0));
        tmp_q.push_back(std::make_tuple(rx, 1, idx, ly_idx, ry_idx, 0));
      }
    }
    std::sort(tmp_q.begin(), tmp_q.end());
    for(auto [x, query_type, idx, ly, ry, val]:tmp_q){
      if(query_type == 0){
        ans[idx] -= bit.getsum(ly, ry);
      }else if(query_type == 1){
        ans[idx] += bit.getsum(ly, ry);
      }else{
        bit.add(ly, val);
      }
    }
  }
public:
  point_add_rectangle_sum(){}
  void add_point(Idx x, Idx y, Val z){
    q.push_back(std::make_tuple(-1, x, 0, y, 0, z));
    question.push_back(0);
  }
  void add_query(Idx lx, Idx rx, Idx ly, Idx ry){
    q.push_back(std::make_tuple(qs++, lx, rx, ly, ry, 0));
    question.push_back(1);
  }
  std::vector<Val> solve(){
    std::vector<Val> ret(qs, 0);
    for(int i=1;i<question.size();i++) question[i] += question[i-1];
    solve(0, q.size(), ret);
    return ret;
  }
};
