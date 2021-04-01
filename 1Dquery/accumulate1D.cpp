#include <vector>

template<typename T>
struct accumulate1D{
  std::vector<T> sum;
  accumulate1D(){}
  accumulate1D(const std::vector<T> &v){
    sum = v;
    for(int i=1;i<v.size();i++) sum[i] = (sum[i-1] + v[i]);
  }
  T getsum(int l, int r){
    if(l>=r) return 0;
    return (l==0?sum[r-1]:(sum[r-1] - sum[l-1]));
  }
};
