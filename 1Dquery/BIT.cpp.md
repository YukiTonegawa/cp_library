---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: 1Dquery/offline_point_set_range_types.cpp
    title: 1Dquery/offline_point_set_range_types.cpp
  - icon: ':heavy_check_mark:'
    path: 2Dquery/offline_point_add_rectangle_sum.cpp
    title: 2Dquery/offline_point_add_rectangle_sum.cpp
  - icon: ':heavy_check_mark:'
    path: 2Dquery/partial_offline_point_add_rectangle_sum.cpp
    title: 2Dquery/partial_offline_point_add_rectangle_sum.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/1Dquery/BIT.test.cpp
    title: verify/1Dquery/BIT.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/2Dquery/fractional_cascading_query_update.test.cpp
    title: verify/2Dquery/fractional_cascading_query_update.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/2Dquery/offline_point_add_rectangle_sum.test.cpp
    title: verify/2Dquery/offline_point_add_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/2Dquery/partial_offline_point_add_rectangle_sum.test.cpp
    title: verify/2Dquery/partial_offline_point_add_rectangle_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"1Dquery/BIT.cpp\"\n#include <vector>\n#include <iostream>\n\
    \ntemplate<typename T = long long>\nstruct BIT{\n  int M=1;\n  std::vector<T>\
    \ sum;\n  BIT(){}\n  BIT(int N): M(N), sum(M+1, 0){}\n  BIT(const std::vector<T>\
    \ &v): M(v.size()), sum(1){\n    sum.insert(sum.begin()+1, v.begin(), v.end());\n\
    \    for(int i=1;i<=v.size();i++){\n      int nxt = i + (i&(-i));\n      if(nxt<=M)\
    \ sum[nxt] += sum[i];\n    }\n  }\n  void add(int k, T x){\n    for(int i=k+1;i<=M;i+=(i&(-i)))\
    \ sum[i] += x;\n  }\n  T getsum(int r){\n    T ret = 0;\n    for(int k=r;k>0;k-=(k&(-k)))\
    \ ret += sum[k];\n    return ret;\n  }\n  T getsum(int l, int r){\n    return\
    \ getsum(r) - getsum(l);\n  }\n};\n"
  code: "#include <vector>\n#include <iostream>\n\ntemplate<typename T = long long>\n\
    struct BIT{\n  int M=1;\n  std::vector<T> sum;\n  BIT(){}\n  BIT(int N): M(N),\
    \ sum(M+1, 0){}\n  BIT(const std::vector<T> &v): M(v.size()), sum(1){\n    sum.insert(sum.begin()+1,\
    \ v.begin(), v.end());\n    for(int i=1;i<=v.size();i++){\n      int nxt = i +\
    \ (i&(-i));\n      if(nxt<=M) sum[nxt] += sum[i];\n    }\n  }\n  void add(int\
    \ k, T x){\n    for(int i=k+1;i<=M;i+=(i&(-i))) sum[i] += x;\n  }\n  T getsum(int\
    \ r){\n    T ret = 0;\n    for(int k=r;k>0;k-=(k&(-k))) ret += sum[k];\n    return\
    \ ret;\n  }\n  T getsum(int l, int r){\n    return getsum(r) - getsum(l);\n  }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: 1Dquery/BIT.cpp
  requiredBy:
  - 1Dquery/offline_point_set_range_types.cpp
  - 2Dquery/partial_offline_point_add_rectangle_sum.cpp
  - 2Dquery/offline_point_add_rectangle_sum.cpp
  timestamp: '2021-03-29 02:52:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/1Dquery/BIT.test.cpp
  - verify/2Dquery/fractional_cascading_query_update.test.cpp
  - verify/2Dquery/offline_point_add_rectangle_sum.test.cpp
  - verify/2Dquery/partial_offline_point_add_rectangle_sum.test.cpp
documentation_of: 1Dquery/BIT.cpp
layout: document
redirect_from:
- /library/1Dquery/BIT.cpp
- /library/1Dquery/BIT.cpp.html
title: 1Dquery/BIT.cpp
---
