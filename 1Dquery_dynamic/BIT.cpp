#include <vector>
#include <iostream>

template<typename T = long long>
struct BIT{
  int M=1;
  std::vector<T> sum;

  BIT(){}
  BIT(int N): M(N+1), sum(M+1, 0){}
  BIT(const std::vector<T> &v): M(v.size() + 1), sum(1){
    sum.insert(sum.begin()+1, v.begin(), v.end());
    for(int i=1;i<=v.size();i++){
      int nxt = i + (i&(-i));
      if(nxt<=M) sum[nxt] += sum[i];
    }
  }
  void add(int k, T x){
    for(int i=k+1;i<=M;i+=(i&(-i))) sum[i] += x;
  }
  T getsum(int r){
    T ret = 0;
    for(int k=r;k>0;k-=(k&(-k))) ret += sum[k];
    return ret;
  }
  T getsum(int l, int r){
    return getsum(r) - getsum(l);
  }
};
