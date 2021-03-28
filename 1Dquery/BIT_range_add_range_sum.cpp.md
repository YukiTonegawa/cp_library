---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/1Dquery/BIT_range_add_range_sum.test.cpp
    title: verify/1Dquery/BIT_range_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"1Dquery/BIT_range_add_range_sum.cpp\"\n#include <vector>\n\
    #include <iostream>\n\ntemplate<typename T = long long>\nstruct BIT{\n  int M=1;\n\
    \  std::vector<std::pair<T, T>> sum;\n  BIT(){}\n  BIT(int N): M(N), sum(M+1,\
    \ {0, 0}){}\n  BIT(const std::vector<T> &v): M(v.size()), sum(M+1, {0, 0}){\n\
    \    for(int i=0;i<v.size();i++) sum[i+1].first = v[i];\n    for(int i=1;i<=v.size();i++){\n\
    \      int nxt = i + (i&(-i));\n      if(nxt<=M) sum[nxt].first += sum[i].first;\n\
    \    }\n  }\n  void add(int k, T x){\n    for(int i=k+1;i<=M;i+=(i&(-i))) sum[i].first\
    \ += x;\n  }\n  void add(int l, int r, T x){\n    T a = x * (++l), b = x * (++r);\n\
    \    for(int i=l;i<=M;i+=(i&(-i))){\n      sum[i].first -= a;\n      sum[i].second\
    \ += x;\n    }\n    for(int i=r;i<=M;i+=(i&(-i))){\n      sum[i].first += b;\n\
    \      sum[i].second -= x;\n    }\n  }\n  T getsum(int r){\n    T a = 0, b = 0;\n\
    \    for(int i=std::min(++r, M);i>0;i-=(i&(-i))){\n      a += sum[i].first;\n\
    \      b += sum[i].second;\n    }\n    return a + (b * r);\n  }\n  T getsum(int\
    \ l, int r){\n    if(l >= r) return 0;\n    return getsum(r) - getsum(l);\n  }\n\
    };\n"
  code: "#include <vector>\n#include <iostream>\n\ntemplate<typename T = long long>\n\
    struct BIT{\n  int M=1;\n  std::vector<std::pair<T, T>> sum;\n  BIT(){}\n  BIT(int\
    \ N): M(N), sum(M+1, {0, 0}){}\n  BIT(const std::vector<T> &v): M(v.size()), sum(M+1,\
    \ {0, 0}){\n    for(int i=0;i<v.size();i++) sum[i+1].first = v[i];\n    for(int\
    \ i=1;i<=v.size();i++){\n      int nxt = i + (i&(-i));\n      if(nxt<=M) sum[nxt].first\
    \ += sum[i].first;\n    }\n  }\n  void add(int k, T x){\n    for(int i=k+1;i<=M;i+=(i&(-i)))\
    \ sum[i].first += x;\n  }\n  void add(int l, int r, T x){\n    T a = x * (++l),\
    \ b = x * (++r);\n    for(int i=l;i<=M;i+=(i&(-i))){\n      sum[i].first -= a;\n\
    \      sum[i].second += x;\n    }\n    for(int i=r;i<=M;i+=(i&(-i))){\n      sum[i].first\
    \ += b;\n      sum[i].second -= x;\n    }\n  }\n  T getsum(int r){\n    T a =\
    \ 0, b = 0;\n    for(int i=std::min(++r, M);i>0;i-=(i&(-i))){\n      a += sum[i].first;\n\
    \      b += sum[i].second;\n    }\n    return a + (b * r);\n  }\n  T getsum(int\
    \ l, int r){\n    if(l >= r) return 0;\n    return getsum(r) - getsum(l);\n  }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: 1Dquery/BIT_range_add_range_sum.cpp
  requiredBy: []
  timestamp: '2021-03-29 02:52:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/1Dquery/BIT_range_add_range_sum.test.cpp
documentation_of: 1Dquery/BIT_range_add_range_sum.cpp
layout: document
redirect_from:
- /library/1Dquery/BIT_range_add_range_sum.cpp
- /library/1Dquery/BIT_range_add_range_sum.cpp.html
title: 1Dquery/BIT_range_add_range_sum.cpp
---
