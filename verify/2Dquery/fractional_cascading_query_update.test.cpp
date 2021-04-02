#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <array>
#include "../../1Dquery/BIT.cpp"
#include "../../2Dquery/fractional_cascading_query.cpp"

#define PROBLEM "https://old.yosupo.jp/problem/point_add_rectangle_sum"

using _val = long long;
using _idx = int;
using _container = BIT<_val>;
_val _id(){return 0;}
_val _merge(_val a, _val b){return a + b;}
_val _query1d(_container &a, int b, int c){return a.getsum(b, c);}
_container _make_container(std::vector<_val> &v){return _container(v);}
void _update1d(_container &a, int b, _val c){a.add(b, c);}
using rect_sum = fractional_cascading_query<_val, _idx, _container, _id, _merge, _query1d, _update1d, _make_container>;

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
  rect_sum rect(v);

  for(int i=0;i<q;i++){
    if(s[i][0]==0){
      auto [num, idx] = rect.find(s[i][1], s[i][2]);
      rect.update_kth(idx, s[i][3]);
    }else std::cout << rect.query(s[i][1], s[i][3], s[i][2], s[i][4]) << '\n';;
  }
}
