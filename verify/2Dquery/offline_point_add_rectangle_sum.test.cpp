#include <vector>
#include <iostream>
#include <tuple>
#include <array>
#include <algorithm>
#include "../../2Dquery/offline_point_add_rectangle_sum.cpp"
#define PROBLEM "https://old.yosupo.jp/problem/point_add_rectangle_sum"

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  int n, q;
  std::cin >> n >> q;
  std::vector<std::tuple<int, int, long long>> v(n);
  std::vector<std::array<long long, 5>> s(q);
  for(int i=0;i<n;i++){
    int a, b, c;
    std::cin >> a >> b >> c;
    v[i] = std::make_tuple(a, b, c);
  }
  for(int i=0;i<q;i++){
    std::cin >> s[i][0] >> s[i][1] >> s[i][2] >> s[i][3];
    if(s[i][0]==0) v.push_back(std::make_tuple(s[i][1], s[i][2], 0));
    else std::cin >> s[i][4];
  }
  point_add_rectangle_sum<long long, int> rect(v);

  for(int i=0;i<q;i++){
    if(s[i][0]==0) rect.add(s[i][1], s[i][2], s[i][3]);
    else std::cout << rect.getsum(s[i][1], s[i][3], s[i][2], s[i][4]) << '\n';;
  }
}
