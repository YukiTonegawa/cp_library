#include <vector>
#include <iostream>
#include <functional>
#include <cassert>
#define PROBLEM "https://atcoder.jp/contests/abc106/tasks/abc106_d"
using namespace std;

template<typename T>
struct accumulate2D{
  vector<vector<T>> sum;
  function<T(T, T)> add = [](T a, T b){return a + b;};
  function<T(T, T)> sub = [](T a, T b){return a - b;};

  accumulate2D(const vector<vector<T>> &v){
    assert(v.size() > 0);
    assert(v[0].size() > 0);
    int n = v.size(), m = v[0].size();
    sum.resize(n, vector<T>(m));
    for(int j=0;j<m;j++){
      for(int i=0;i<n;i++){
        sum[i][j] = add((i==0?0:sum[i-1][j]), v[i][j]);
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        sum[i][j] = add(sum[i][j], (j==0?0:sum[i][j-1]));
      }
    }
  }
  
  T getsum(int lx, int rx, int ly, int ry){
    T upper_left = (lx==0||ly==0?0:sum[lx-1][ly-1]);
    T lower_left = (rx==0||ly==0?0:sum[rx-1][ly-1]);
    T upper_right = (lx==0||ry==0?0:sum[lx-1][ry-1]);
    T lower_right = (rx==0||ry==0?0:sum[rx-1][ry-1]);
    return sub(add(upper_left, lower_right), add(lower_left, upper_right));
  }
};

int main(){
  int n, m, q;
  std::cin >> n >> m >> q;
  vector<vector<int>> v(n, vector<int>(n, 0));
  for(int i=0;i<m;i++){
    int l, r;
    std::cin >> l >> r;
    v[l-1][r-1]++;
  }
  accumulate2D ac(v);
  for(int i=0;i<q;i++){
    int l, r;
    std::cin >> l >> r;
    std::cout << ac.getsum(l-1, n, 0, r) << '\n';
  }
}
