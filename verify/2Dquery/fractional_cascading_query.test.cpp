#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <array>
#include "../../1Dquery/accumulate1D.cpp"
#include "../../2Dquery/fractional_cascading_query.cpp"

#define PROBLEM "https://old.yosupo.jp/problem/rectangle_sum"

using _val = long long;
using _idx = int;
using _container = accumulate1D<_val>;
_val _id(){return 0;}
_val _merge(_val a, _val b){return a + b;}
_val _query1d(_container &a, int b, int c){return a.getsum(b, c);}
_container _make_container(std::vector<_val> &v){return _container(v);}
using rect_sum = fractional_cascading_query<_val, _idx, _container, _id, _merge, _query1d, _make_container>;

#include <iostream>
int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  using point = std::tuple<int, int, long long>;
  int n, q;
  std::cin >> n >> q;
  std::vector<point> p(n);
  for(int i=0;i<n;i++){
    int a, b, c;
    std::cin >> a >> b >> c;
    p[i] = std::make_tuple(a, b, c);
  }
  rect_sum rect(p);
  for(int i=0;i<q;i++){
    int lx, ly, rx, ry;
    std::cin >> lx >> ly >> rx >> ry;
    std::cout << rect.query(lx, rx, ly, ry) << '\n';
  }
}
