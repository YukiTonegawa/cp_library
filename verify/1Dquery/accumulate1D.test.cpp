#include <vector>
#include <cstdio>
#include "../../1Dquery/accumulate1D.cpp"
#define PROBLEM "https://old.yosupo.jp/problem/static_range_sum"

int main(){
  int n, q;scanf("%d %d", &n, &q);
  std::vector<long long> v(n);
  for(int i=0;i<n;i++) scanf("%lld", &v[i]);
  accumulate1D<long long> ac(v);
  for(int i=0;i<q;i++){
    int l, r;scanf("%d %d", &l, &r);
    printf("%lld\n", ac.query(l, r));
  }
}
