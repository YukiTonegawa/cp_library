#include <vector>
#include <iostream>

template<typename T = long long>
struct BIT{
  int M=1;
  std::vector<std::pair<T, T>> sum;
  BIT(){}
  BIT(int N): M(N), sum(M+1, {0, 0}){}
  BIT(const std::vector<T> &v): M(v.size()), sum(M+1, {0, 0}){
    for(int i=0;i<v.size();i++) sum[i+1].first = v[i];
    for(int i=1;i<=v.size();i++){
      int nxt = i + (i&(-i));
      if(nxt<=M) sum[nxt].first += sum[i].first;
    }
  }
  void add(int k, T x){
    for(int i=k+1;i<=M;i+=(i&(-i))) sum[i].first += x;
  }
  void add(int l, int r, T x){
    T a = x * (++l), b = x * (++r);
    for(int i=l;i<=M;i+=(i&(-i))){
      sum[i].first -= a;
      sum[i].second += x;
    }
    for(int i=r;i<=M;i+=(i&(-i))){
      sum[i].first += b;
      sum[i].second -= x;
    }
  }
  T getsum(int r){
    T a = 0, b = 0;
    for(int i=std::min(++r, M);i>0;i-=(i&(-i))){
      a += sum[i].first;
      b += sum[i].second;
    }
    return a + (b * r);
  }
  T getsum(int l, int r){
    if(l >= r) return 0;
    return getsum(r) - getsum(l);
  }
};
