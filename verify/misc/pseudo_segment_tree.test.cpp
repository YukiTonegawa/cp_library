#include <iostream>
#include <unordered_map>
#include "../../misc/pseudo_segment_tree.cpp"
#define PROBLEM "https://old.yosupo.jp/problem/point_add_range_sum"

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  int n, q;std::cin >> n >> q;
  std::unordered_map<int, long long> sum;
  pseudo_segment_tree<int> segment(n);
  for(int i=0;i<n;i++){
    int x;std::cin >> x;
    auto indices = segment.point_to_index(i);
    for(auto index:indices) sum[index] += x;
  }
  for(int i=0;i<q;i++){
    int a, b, c;std::cin >> a >> b >> c;
    if(a==0){
      auto indices = segment.point_to_index(b);
      for(auto index:indices) sum[index] += c;
    }else{
      long long ans = 0;
      auto indices = segment.range_to_index(b, c);
      for(auto index:indices) ans += sum[index];
      std::cout << ans << '\n';
    }
  }
}
