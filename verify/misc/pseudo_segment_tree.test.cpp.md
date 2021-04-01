---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: misc/pseudo_segment_tree.cpp
    title: misc/pseudo_segment_tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/789
    links:
    - https://yukicoder.me/problems/no/789
  bundledCode: "#line 1 \"verify/misc/pseudo_segment_tree.test.cpp\"\n#include <iostream>\n\
    #include <unordered_map>\n#line 1 \"misc/pseudo_segment_tree.cpp\"\n#include <vector>\n\
    #include <cassert>\n#include <algorithm>\n\ntemplate<typename Idx = int, int bitlen\
    \ = sizeof(Idx) * 8>\nstruct pseudo_segment_tree{\n  Idx M, N;\n  pseudo_segment_tree(Idx\
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
    \ 1) >> 1;\n      ret.push_back(k);\n    }\n    return ret;\n  }\n};\n#line 4\
    \ \"verify/misc/pseudo_segment_tree.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/789\"\
    \n\nint main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \  int q;std::cin >> q;\n  pseudo_segment_tree segment(1000000001);\n  std::unordered_map<int,\
    \ long long> sum;\n  long long ans = 0;\n  for(int i=0;i<q;i++){\n    int t, a,\
    \ b;std::cin >> t >> a >> b;\n    if(t == 0){\n      auto indices = segment.point_to_index(a);\n\
    \      for(auto idx : indices) sum[idx] += b;\n    }else{\n      auto indices\
    \ = segment.range_to_index(a, b + 1);\n      for(auto idx : indices) ans += sum[idx];\n\
    \    }\n  }\n  std::cout << ans << '\\n';\n}\n"
  code: "#include <iostream>\n#include <unordered_map>\n#include \"../../misc/pseudo_segment_tree.cpp\"\
    \n#define PROBLEM \"https://yukicoder.me/problems/no/789\"\n\nint main(){\n  std::cin.tie(nullptr);\n\
    \  std::ios::sync_with_stdio(false);\n  int q;std::cin >> q;\n  pseudo_segment_tree\
    \ segment(1000000001);\n  std::unordered_map<int, long long> sum;\n  long long\
    \ ans = 0;\n  for(int i=0;i<q;i++){\n    int t, a, b;std::cin >> t >> a >> b;\n\
    \    if(t == 0){\n      auto indices = segment.point_to_index(a);\n      for(auto\
    \ idx : indices) sum[idx] += b;\n    }else{\n      auto indices = segment.range_to_index(a,\
    \ b + 1);\n      for(auto idx : indices) ans += sum[idx];\n    }\n  }\n  std::cout\
    \ << ans << '\\n';\n}\n"
  dependsOn:
  - misc/pseudo_segment_tree.cpp
  isVerificationFile: true
  path: verify/misc/pseudo_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2021-04-01 21:41:27+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/misc/pseudo_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/misc/pseudo_segment_tree.test.cpp
- /verify/verify/misc/pseudo_segment_tree.test.cpp.html
title: verify/misc/pseudo_segment_tree.test.cpp
---
