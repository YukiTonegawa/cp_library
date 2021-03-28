---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"1Dquery_dynamic/BIT.cpp\"\n#include <vector>\n#include <iostream>\n\
    \ntemplate<typename T = long long>\nstruct BIT{\n  int M=1;\n  std::vector<T>\
    \ sum;\n\n  BIT(){}\n  BIT(int N): M(N+1), sum(M+1, 0){}\n  BIT(const std::vector<T>\
    \ &v): M(v.size() + 1), sum(1){\n    sum.insert(sum.begin()+1, v.begin(), v.end());\n\
    \    for(int i=1;i<=v.size();i++){\n      int nxt = i + (i&(-i));\n      if(nxt<=M)\
    \ sum[nxt] += sum[i];\n    }\n  }\n  void add(int k, T x){\n    for(int i=k+1;i<=M;i+=(i&(-i)))\
    \ sum[i] += x;\n  }\n  T getsum(int r){\n    T ret = 0;\n    for(int k=r;k>0;k-=(k&(-k)))\
    \ ret += sum[k];\n    return ret;\n  }\n  T getsum(int l, int r){\n    return\
    \ getsum(r) - getsum(l);\n  }\n};\n"
  code: "#include <vector>\n#include <iostream>\n\ntemplate<typename T = long long>\n\
    struct BIT{\n  int M=1;\n  std::vector<T> sum;\n\n  BIT(){}\n  BIT(int N): M(N+1),\
    \ sum(M+1, 0){}\n  BIT(const std::vector<T> &v): M(v.size() + 1), sum(1){\n  \
    \  sum.insert(sum.begin()+1, v.begin(), v.end());\n    for(int i=1;i<=v.size();i++){\n\
    \      int nxt = i + (i&(-i));\n      if(nxt<=M) sum[nxt] += sum[i];\n    }\n\
    \  }\n  void add(int k, T x){\n    for(int i=k+1;i<=M;i+=(i&(-i))) sum[i] += x;\n\
    \  }\n  T getsum(int r){\n    T ret = 0;\n    for(int k=r;k>0;k-=(k&(-k))) ret\
    \ += sum[k];\n    return ret;\n  }\n  T getsum(int l, int r){\n    return getsum(r)\
    \ - getsum(l);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: 1Dquery_dynamic/BIT.cpp
  requiredBy: []
  timestamp: '2021-03-23 19:56:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: 1Dquery_dynamic/BIT.cpp
layout: document
redirect_from:
- /library/1Dquery_dynamic/BIT.cpp
- /library/1Dquery_dynamic/BIT.cpp.html
title: 1Dquery_dynamic/BIT.cpp
---
