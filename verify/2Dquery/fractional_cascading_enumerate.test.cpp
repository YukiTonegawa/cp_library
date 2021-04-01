#include <iostream>
#include <tuple>
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C"
#include "../../2Dquery/fractional_cascading_enumerate.cpp"


#include <iostream>
int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::tuple<int, int, int>> v(n);
  int shift = 1000000000;
  for(int i=0;i<n;i++){
    int x, y;
    std::cin >> x >> y;
    v[i] = std::make_tuple(x + shift, y + shift, i);
  }
  fractional_cascading_enumerate<int, int> rect(v);
  int q;std::cin >> q;
  for(int i=0;i<q;i++){
    int lx, rx, ly, ry;
    std::cin >> lx >> rx >> ly >> ry;
    auto P = rect.query(lx + shift, rx + shift + 1, ly + shift, ry + shift + 1);
    std::vector<int> ans;
    for(auto [_, __, idx] : P) ans.push_back(idx);
    std::sort(ans.begin(), ans.end());
    for(int idx:ans) std::cout << idx << '\n';
    std::cout << '\n';
  }
}
