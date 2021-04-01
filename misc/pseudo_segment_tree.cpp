#include <vector>
#include <cassert>
#include <algorithm>

template<typename Idx = int, int bitlen = sizeof(Idx) * 8>
struct pseudo_segment_tree{
  Idx M, N;
  pseudo_segment_tree(Idx n):N(n){
    M = 1;
    while(M < N) M <<= 1;
  }
  int depth(Idx k){
    if(bitlen <= 32) return 31 - __builtin_clz(k + 1);
    return 63 - __builtin_clzll(k + 1);
  }
  Idx width(Idx k){
    return M >> depth(k);
  }
  bool is_leaf(Idx k){
    return width(k) == (Idx)1;
  }
  std::pair<Idx, Idx> index_to_range(Idx k){
    assert(0 <= k && k < 2 * M - 1);
    int dep = depth(k);
    Idx offset = (k + 1) - ((Idx)1 << dep);
    Idx wid = M >> dep;
    return std::make_pair(offset * wid, (offset + 1) * wid);
  }
  std::vector<Idx> range_to_index(Idx l, Idx r){
    l = std::max(l, 0), r = std::min(r, N);
    assert(l <= r);
    l += M, r += M;
    std::vector<Idx> left, right;
    while(l < r){
      if(l & 1) left.push_back((l++) - 1);
      if(r & 1) right.push_back((--r) - 1);
      l >>= 1;
      r >>= 1;
    }
    std::reverse(right.begin(), right.end());
    left.insert(left.end(), right.begin(), right.end());
    return left;
  }
  std::vector<Idx> point_to_index(Idx k){
    assert(0 <= k && k < N);
    k += M - 1;
    std::vector<Idx> ret{k};
    while(k){
      k = (k - 1) >> 1;
      ret.push_back(k);
    }
    return ret;
  }
};
