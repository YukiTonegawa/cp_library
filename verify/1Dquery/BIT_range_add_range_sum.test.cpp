#include <vector>
#include <iostream>
#include "../../1Dquery/BIT_range_add_range_sum.cpp"
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

int main(){
  int n, q;scanf("%d %d", &n, &q);
  BIT s(n);
  for(int i=0;i<q;i++){
    int a, b, c;scanf("%d %d %d", &a, &b, &c);
    if(a==0){
      int d;scanf("%d", &d);
      s.add(b-1, c, d);
    }else{
      printf("%lld\n", s.getsum(b-1, c));
    }
  }
}
