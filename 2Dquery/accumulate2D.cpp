#include <vector>
#include <iostream>
#include <functional>
#include <cassert>

template<typename T>
struct accumulate2D{
  int n, m;
  std::vector<std::vector<T>> sum;
  accumulate2D(){}
  accumulate2D(const std::vector<std::vector<T>> &v){
    assert(v.size() > 0);
    assert(v[0].size() > 0);
    n = v.size(), m = v[0].size();
    sum.resize(n, std::vector<T>(m));
    for(int j=0;j<m;j++){
      for(int i=0;i<n;i++){
        sum[i][j] = ((i==0?0:sum[i-1][j]) + v[i][j]);
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        sum[i][j] = (sum[i][j] + (j==0?0:sum[i][j-1]));
      }
    }
  }
  T getsum(int lx, int rx, int ly, int ry){
    lx = std::max(0, lx);
    rx = std::min(n, rx);
    ly = std::max(0, ly);
    ry = std::min(n, ry);
    if(lx > rx || ly > ry) return 0;
    T upper_left = (lx==0||ly==0?0:sum[lx-1][ly-1]);
    T lower_left = (rx==0||ly==0?0:sum[rx-1][ly-1]);
    T upper_right = (lx==0||ry==0?0:sum[lx-1][ry-1]);
    T lower_right = (rx==0||ry==0?0:sum[rx-1][ry-1]);
    return ((upper_left + lower_right) - (lower_left + upper_right));
  }
};
