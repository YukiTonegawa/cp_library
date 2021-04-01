---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: 1Dquery/accumulate1D.cpp
    title: 1Dquery/accumulate1D.cpp
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
  bundledCode: "#line 1 \"verify/1Dquery/accumulate1D.test.cpp\"\n#include <vector>\n\
    #include <cstdio>\n#line 2 \"1Dquery/accumulate1D.cpp\"\n\ntemplate<typename T>\n\
    struct accumulate1D{\n  std::vector<T> sum;\n  accumulate1D(){}\n  accumulate1D(const\
    \ std::vector<T> &v){\n    sum = v;\n    for(int i=1;i<v.size();i++) sum[i] =\
    \ (sum[i-1] + v[i]);\n  }\n  T getsum(int l, int r){\n    if(l>=r) return 0;\n\
    \    return (l==0?sum[r-1]:(sum[r-1] - sum[l-1]));\n  }\n};\n#line 4 \"verify/1Dquery/accumulate1D.test.cpp\"\
    \n#define PROBLEM \"https://old.yosupo.jp/problem/static_range_sum\"\n\nint main(){\n\
    \  int n, q;scanf(\"%d %d\", &n, &q);\n  std::vector<long long> v(n);\n  for(int\
    \ i=0;i<n;i++) scanf(\"%lld\", &v[i]);\n  accumulate1D<long long> ac(v);\n  for(int\
    \ i=0;i<q;i++){\n    int l, r;scanf(\"%d %d\", &l, &r);\n    printf(\"%lld\\n\"\
    , ac.getsum(l, r));\n  }\n}\n"
  code: "#include <vector>\n#include <cstdio>\n#include \"../../1Dquery/accumulate1D.cpp\"\
    \n#define PROBLEM \"https://old.yosupo.jp/problem/static_range_sum\"\n\nint main(){\n\
    \  int n, q;scanf(\"%d %d\", &n, &q);\n  std::vector<long long> v(n);\n  for(int\
    \ i=0;i<n;i++) scanf(\"%lld\", &v[i]);\n  accumulate1D<long long> ac(v);\n  for(int\
    \ i=0;i<q;i++){\n    int l, r;scanf(\"%d %d\", &l, &r);\n    printf(\"%lld\\n\"\
    , ac.getsum(l, r));\n  }\n}\n"
  dependsOn:
  - 1Dquery/accumulate1D.cpp
  isVerificationFile: true
  path: verify/1Dquery/accumulate1D.test.cpp
  requiredBy: []
  timestamp: '2021-04-01 22:47:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/1Dquery/accumulate1D.test.cpp
layout: document
redirect_from:
- /verify/verify/1Dquery/accumulate1D.test.cpp
- /verify/verify/1Dquery/accumulate1D.test.cpp.html
title: verify/1Dquery/accumulate1D.test.cpp
---
