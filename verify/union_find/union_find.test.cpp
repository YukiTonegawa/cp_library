#include <vector>
#include <iostream>
#include <numeric>
#include "../../union_find/union_find.cpp"
#define PROBLEM "https://old.yosupo.jp/problem/unionfind"
using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int a, b, c, n, q;
  std::cin >> n >> q;
  union_find uf(n);
  for(int i=0;i<q;i++){
    std::cin >> a >> b >> c;
    if(a==0) uf.unite(b, c);
    else std::cout << int(uf.same(b, c)) << '\n';
  }
}
