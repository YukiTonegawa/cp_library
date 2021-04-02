#include <iostream>
#include <limits>
#include <vector>
#include <cmath>
#include <cassert>
#define PROBLEM "https://old.yosupo.jp/problem/kth_root_integer"
#include "../../math/kth_root.cpp"

int main(){
	int T;scanf("%d", &T);
	for(int i=0;i<T;i++) {
    uint64_t x, k;scanf("%llu %llu", &x, &k);
    uint64_t ans1 = kth_root_fast(x, k);
    uint64_t ans2 = kth_root_stable(x, k);
    assert(ans1 == ans2);
    printf("%llu\n", ans1);
  }
}
