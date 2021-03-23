---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://old.yosupo.jp/problem/static_range_sum
    links:
    - https://old.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"verify/1Dquery_dynamic/BIT.test.cpp\"\n#include <vector>\n\
    #include <iostream>\n#define PROBLEM \"https://old.yosupo.jp/problem/static_range_sum\"\
    \n\ntemplate<typename T = long long>\nstruct BIT{\n  int M=1;\n  std::vector<T>\
    \ sum;\n\n  BIT(){}\n  BIT(int N): M(N+1), sum(M+1, 0){}\n  BIT(const std::vector<T>\
    \ &v): M(v.size() + 1), sum(1){\n    sum.insert(sum.begin()+1, v.begin(), v.end());\n\
    \    for(int i=1;i<=v.size();i++){\n      int nxt = i + (i&(-i));\n      if(nxt<=M)\
    \ sum[nxt] += sum[i];\n    }\n  }\n  void add(int k, T x){\n    for(int i=k+1;i<=M;i+=(i&(-i)))\
    \ sum[i] += x;\n  }\n  T getsum(int r){\n    T ret = 0;\n    for(int k=r;k>0;k-=(k&(-k)))\
    \ ret += sum[k];\n    return ret;\n  }\n  T getsum(int l, int r){\n    return\
    \ getsum(r) - getsum(l);\n  }\n};\n\nint main(){\n  long long n, q;\n  std::cin\
    \ >> n >> q;\n  std::vector<long long> v(n);\n  for(int i=0;i<n;i++) std::cin\
    \ >> v[i];\n  BIT bit(v);\n  for(int i=0;i<q;i++){\n    long long l, r;\n    std::cin\
    \ >> l >> r;\n    long long ans = bit.getsum(l, r);\n    std::cout << ans << '\\\
    n';\n  }\n}\n"
  code: "#include <vector>\n#include <iostream>\n#define PROBLEM \"https://old.yosupo.jp/problem/static_range_sum\"\
    \n\ntemplate<typename T = long long>\nstruct BIT{\n  int M=1;\n  std::vector<T>\
    \ sum;\n\n  BIT(){}\n  BIT(int N): M(N+1), sum(M+1, 0){}\n  BIT(const std::vector<T>\
    \ &v): M(v.size() + 1), sum(1){\n    sum.insert(sum.begin()+1, v.begin(), v.end());\n\
    \    for(int i=1;i<=v.size();i++){\n      int nxt = i + (i&(-i));\n      if(nxt<=M)\
    \ sum[nxt] += sum[i];\n    }\n  }\n  void add(int k, T x){\n    for(int i=k+1;i<=M;i+=(i&(-i)))\
    \ sum[i] += x;\n  }\n  T getsum(int r){\n    T ret = 0;\n    for(int k=r;k>0;k-=(k&(-k)))\
    \ ret += sum[k];\n    return ret;\n  }\n  T getsum(int l, int r){\n    return\
    \ getsum(r) - getsum(l);\n  }\n};\n\nint main(){\n  long long n, q;\n  std::cin\
    \ >> n >> q;\n  std::vector<long long> v(n);\n  for(int i=0;i<n;i++) std::cin\
    \ >> v[i];\n  BIT bit(v);\n  for(int i=0;i<q;i++){\n    long long l, r;\n    std::cin\
    \ >> l >> r;\n    long long ans = bit.getsum(l, r);\n    std::cout << ans << '\\\
    n';\n  }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/1Dquery_dynamic/BIT.test.cpp
  requiredBy: []
  timestamp: '2021-03-23 19:56:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/1Dquery_dynamic/BIT.test.cpp
layout: document
redirect_from:
- /verify/verify/1Dquery_dynamic/BIT.test.cpp
- /verify/verify/1Dquery_dynamic/BIT.test.cpp.html
title: verify/1Dquery_dynamic/BIT.test.cpp
---
