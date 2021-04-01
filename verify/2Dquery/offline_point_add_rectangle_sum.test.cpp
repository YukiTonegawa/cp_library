#include <iostream>
#include "../../2Dquery/offline_point_add_rectangle_sum.cpp"
#define PROBLEM "https://old.yosupo.jp/problem/point_add_rectangle_sum"

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  int n, q;
  std::cin >> n >> q;
  point_add_rectangle_sum<int, long long> rect;
  for(int i=0;i<n;i++){
    int a, b, c;
    std::cin >> a >> b >> c;
    rect.add_point(a, b, c);
  }
  for(int i=0;i<q;i++){
    int a, b, c, d, e;
    std::cin >> a >> b >> c >> d;
    if(a==0) rect.add_point(b, c, d);
    else{
      std::cin >> e;
      rect.add_query(b, d, c, e);
    }
  }
  auto ans = rect.solve();
  for(int i=0;i<ans.size();i++) std::cout << ans[i] << '\n';
}
