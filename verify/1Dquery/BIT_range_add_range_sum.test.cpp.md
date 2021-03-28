---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: 1Dquery/BIT_range_add_range_sum.cpp
    title: 1Dquery/BIT_range_add_range_sum.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "#line 1 \"verify/1Dquery/BIT_range_add_range_sum.test.cpp\"\n#include\
    \ <vector>\n#include <iostream>\n#line 3 \"1Dquery/BIT_range_add_range_sum.cpp\"\
    \n\ntemplate<typename T = long long>\nstruct BIT{\n  int M=1;\n  std::vector<std::pair<T,\
    \ T>> sum;\n  BIT(){}\n  BIT(int N): M(N), sum(M+1, {0, 0}){}\n  BIT(const std::vector<T>\
    \ &v): M(v.size()), sum(M+1, {0, 0}){\n    for(int i=0;i<v.size();i++) sum[i+1].first\
    \ = v[i];\n    for(int i=1;i<=v.size();i++){\n      int nxt = i + (i&(-i));\n\
    \      if(nxt<=M) sum[nxt].first += sum[i].first;\n    }\n  }\n  void add(int\
    \ k, T x){\n    for(int i=k+1;i<=M;i+=(i&(-i))) sum[i].first += x;\n  }\n  void\
    \ add(int l, int r, T x){\n    T a = x * (++l), b = x * (++r);\n    for(int i=l;i<=M;i+=(i&(-i))){\n\
    \      sum[i].first -= a;\n      sum[i].second += x;\n    }\n    for(int i=r;i<=M;i+=(i&(-i))){\n\
    \      sum[i].first += b;\n      sum[i].second -= x;\n    }\n  }\n  T getsum(int\
    \ r){\n    T a = 0, b = 0;\n    for(int i=std::min(++r, M);i>0;i-=(i&(-i))){\n\
    \      a += sum[i].first;\n      b += sum[i].second;\n    }\n    return a + (b\
    \ * r);\n  }\n  T getsum(int l, int r){\n    if(l >= r) return 0;\n    return\
    \ getsum(r) - getsum(l);\n  }\n};\n#line 4 \"verify/1Dquery/BIT_range_add_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n\nint main(){\n  int n, q;scanf(\"%d %d\", &n, &q);\n  BIT s(n);\n  for(int\
    \ i=0;i<q;i++){\n    int a, b, c;scanf(\"%d %d %d\", &a, &b, &c);\n    if(a==0){\n\
    \      int d;scanf(\"%d\", &d);\n      s.add(b-1, c, d);\n    }else{\n      printf(\"\
    %lld\\n\", s.getsum(b-1, c));\n    }\n  }\n}\n"
  code: "#include <vector>\n#include <iostream>\n#include \"../../1Dquery/BIT_range_add_range_sum.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n\nint main(){\n  int n, q;scanf(\"%d %d\", &n, &q);\n  BIT s(n);\n  for(int\
    \ i=0;i<q;i++){\n    int a, b, c;scanf(\"%d %d %d\", &a, &b, &c);\n    if(a==0){\n\
    \      int d;scanf(\"%d\", &d);\n      s.add(b-1, c, d);\n    }else{\n      printf(\"\
    %lld\\n\", s.getsum(b-1, c));\n    }\n  }\n}\n"
  dependsOn:
  - 1Dquery/BIT_range_add_range_sum.cpp
  isVerificationFile: true
  path: verify/1Dquery/BIT_range_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2021-03-29 03:57:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/1Dquery/BIT_range_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/1Dquery/BIT_range_add_range_sum.test.cpp
- /verify/verify/1Dquery/BIT_range_add_range_sum.test.cpp.html
title: verify/1Dquery/BIT_range_add_range_sum.test.cpp
---
