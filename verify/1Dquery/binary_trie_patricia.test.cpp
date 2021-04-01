#include <iostream>
#include "../../1Dquery/binary_trie_patricia.cpp"
#define PROBLEM "https://old.yosupo.jp/problem/set_xor_min"

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  int q;
  std::cin >> q;
  binary_trie t;
  for(int i=0;i<q;i++){
    int a, b;
    std::cin >> a >> b;
    if(a==0){
      t.insert(b);
    }else if(a==1){
      t.erase(b);
    }else{
      t.xor_all(b);
      std::cout << t.kth_element(0) << '\n';
      t.xor_all(b);
    }
  }
}
