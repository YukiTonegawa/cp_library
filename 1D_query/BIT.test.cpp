#include <vector>
#include <iostream>
#define PROBLEM "https://old.yosupo.jp/problem/static_range_sum"

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

int main(){
  long long n, q;
  std::cin >> n >> q;
  std::vector<long long> v(n);
  for(int i=0;i<n;i++) std::cin >> v[i];
  BIT bit(v);
  for(int i=0;i<q;i++){
    long long l, r;
    std::cin >> l >> r;
    long long ans = bit.getsum(l, r);
    std::cout << ans << '\n';
  }
}
