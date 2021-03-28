#include <vector>
#include <iostream>
#include "../../1Dquery/BIT.cpp"
#define PROBLEM "https://old.yosupo.jp/problem/static_range_sum"

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
