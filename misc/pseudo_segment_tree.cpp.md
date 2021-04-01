---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/misc/pseudo_segment_tree.test.cpp
    title: verify/misc/pseudo_segment_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/pseudo_segment_tree.cpp\"\n#include <vector>\n#include\
    \ <cassert>\n#include <algorithm>\n\ntemplate<typename Idx = int, int bitlen =\
    \ sizeof(Idx) * 8>\nstruct pseudo_segment_tree{\n  Idx M, N;\n  pseudo_segment_tree(Idx\
    \ n):N(n){\n    M = 1;\n    while(M < N) M <<= 1;\n  }\n  int depth(Idx k){\n\
    \    if(bitlen <= 32) return 31 - __builtin_clz(k + 1);\n    return 63 - __builtin_clzll(k\
    \ + 1);\n  }\n  Idx width(Idx k){\n    return M >> depth(k);\n  }\n  bool is_leaf(Idx\
    \ k){\n    return width(k) == (Idx)1;\n  }\n  std::pair<Idx, Idx> index_to_range(Idx\
    \ k){\n    assert(0 <= k && k < 2 * M - 1);\n    int dep = depth(k);\n    Idx\
    \ offset = (k + 1) - ((Idx)1 << dep);\n    Idx wid = M >> dep;\n    return std::make_pair(offset\
    \ * wid, (offset + 1) * wid);\n  }\n  std::vector<Idx> range_to_index(Idx l, Idx\
    \ r){\n    l = std::max(l, 0), r = std::min(r, N);\n    assert(l <= r);\n    l\
    \ += M, r += M;\n    std::vector<Idx> left, right;\n    while(l < r){\n      if(l\
    \ & 1) left.push_back((l++) - 1);\n      if(r & 1) right.push_back((--r) - 1);\n\
    \      l >>= 1;\n      r >>= 1;\n    }\n    std::reverse(right.begin(), right.end());\n\
    \    left.insert(left.end(), right.begin(), right.end());\n    return left;\n\
    \  }\n  std::vector<Idx> point_to_index(Idx k){\n    assert(0 <= k && k < N);\n\
    \    k += M - 1;\n    std::vector<Idx> ret{k};\n    while(k){\n      k = (k -\
    \ 1) >> 1;\n      ret.push_back(k);\n    }\n    return ret;\n  }\n};\n"
  code: "#include <vector>\n#include <cassert>\n#include <algorithm>\n\ntemplate<typename\
    \ Idx = int, int bitlen = sizeof(Idx) * 8>\nstruct pseudo_segment_tree{\n  Idx\
    \ M, N;\n  pseudo_segment_tree(Idx n):N(n){\n    M = 1;\n    while(M < N) M <<=\
    \ 1;\n  }\n  int depth(Idx k){\n    if(bitlen <= 32) return 31 - __builtin_clz(k\
    \ + 1);\n    return 63 - __builtin_clzll(k + 1);\n  }\n  Idx width(Idx k){\n \
    \   return M >> depth(k);\n  }\n  bool is_leaf(Idx k){\n    return width(k) ==\
    \ (Idx)1;\n  }\n  std::pair<Idx, Idx> index_to_range(Idx k){\n    assert(0 <=\
    \ k && k < 2 * M - 1);\n    int dep = depth(k);\n    Idx offset = (k + 1) - ((Idx)1\
    \ << dep);\n    Idx wid = M >> dep;\n    return std::make_pair(offset * wid, (offset\
    \ + 1) * wid);\n  }\n  std::vector<Idx> range_to_index(Idx l, Idx r){\n    l =\
    \ std::max(l, 0), r = std::min(r, N);\n    assert(l <= r);\n    l += M, r += M;\n\
    \    std::vector<Idx> left, right;\n    while(l < r){\n      if(l & 1) left.push_back((l++)\
    \ - 1);\n      if(r & 1) right.push_back((--r) - 1);\n      l >>= 1;\n      r\
    \ >>= 1;\n    }\n    std::reverse(right.begin(), right.end());\n    left.insert(left.end(),\
    \ right.begin(), right.end());\n    return left;\n  }\n  std::vector<Idx> point_to_index(Idx\
    \ k){\n    assert(0 <= k && k < N);\n    k += M - 1;\n    std::vector<Idx> ret{k};\n\
    \    while(k){\n      k = (k - 1) >> 1;\n      ret.push_back(k);\n    }\n    return\
    \ ret;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/pseudo_segment_tree.cpp
  requiredBy: []
  timestamp: '2021-04-01 21:41:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/misc/pseudo_segment_tree.test.cpp
documentation_of: misc/pseudo_segment_tree.cpp
layout: document
redirect_from:
- /library/misc/pseudo_segment_tree.cpp
- /library/misc/pseudo_segment_tree.cpp.html
title: misc/pseudo_segment_tree.cpp
---
