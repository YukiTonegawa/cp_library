#include <iostream>
#include <limits>
#include <vector>
#include <cmath>

uint64_t kth_root_stable(uint64_t x, uint64_t k){
  if(x==0) return 0;
  if(k==1||x==1) return x;
  if(k>=64) return 1;
  uint64_t l = 1, r = x;
  const static uint64_t threshold = std::numeric_limits<uint64_t>::max();
  while(r-l>1){
    bool f = false;
    uint64_t mid = l + ((r - l) >> 1), z = 1;
    uint64_t lim = threshold / mid;
    for(int i=0;i<k;i++){
      if(z > lim){
        f = true;
        break;
      }
      z *= mid;
    }
    if(f | (z > x)) r = mid;
    else l = mid;
  }
  return l;
}

uint64_t kth_root_fast(uint64_t x, uint64_t k){
  if(x<=1) return (k==0?1:x);
  if(k<=2) return (k<=1?k==0?1:x:sqrtl(x));
  if(k>=64||!(x>>k)) return 1;
  const static int sz[8] = {40,31,27,24,22,21,20,19};
  static std::vector<std::vector<uint64_t>> table;
  if(table.empty()){
    table.resize(40);
    for(int i=0;i<40;i++)for(uint64_t j=0;j<8&&sz[j]>i;j++)table[i].push_back((i==0?uint64_t(1):table[i-1][j])*(j+3));
  }
  if(k>=19){
    int ans = 10;
    for(;ans>2;ans--){
      if(sz[ans-3]<k || table[k-1][ans-3] > x) continue;
      return ans;
    }
    return 2;
  }
  uint64_t r = (k!=3?pow(x, (1.0 + 1e-6)/k):cbrt(x)+1);
  const static uint64_t threshold = std::numeric_limits<uint64_t>::max();
  while(true){
    uint64_t lim = threshold / r, z = 1;
    for(int i=0;i<k;i++, z*=r) if(z > lim) goto upper;
    if(z > x) upper:r--;
    else break;
  }
  return r;
}
