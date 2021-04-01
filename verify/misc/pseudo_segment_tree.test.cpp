#include <iostream>
#include <unordered_map>
#include "../../misc/pseudo_segment_tree.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/789"

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  int q;std::cin >> q;
  pseudo_segment_tree segment(1000000001);
  std::unordered_map<int, long long> sum;
  long long ans = 0;
  for(int i=0;i<q;i++){
    int t, a, b;std::cin >> t >> a >> b;
    if(t == 0){
      auto indices = segment.point_to_index(a);
      for(auto idx : indices) sum[idx] += b;
    }else{
      auto indices = segment.range_to_index(a, b + 1);
      for(auto idx : indices) ans += sum[idx];
    }
  }
  std::cout << ans << '\n';
}
