---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/1Dquery/accumulate1D.test.cpp
    title: verify/1Dquery/accumulate1D.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/2Dquery/fractional_cascading_query.test.cpp
    title: verify/2Dquery/fractional_cascading_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"1Dquery/accumulate1D.cpp\"\n#include <vector>\n\ntemplate<typename\
    \ T>\nstruct accumulate1D{\n  std::vector<T> sum;\n  accumulate1D(){}\n  accumulate1D(const\
    \ std::vector<T> &v){\n    sum = v;\n    for(int i=1;i<v.size();i++) sum[i] =\
    \ (sum[i-1] + v[i]);\n  }\n  T getsum(int l, int r){\n    if(l>=r) return 0;\n\
    \    return (l==0?sum[r-1]:(sum[r-1] - sum[l-1]));\n  }\n};\n"
  code: "#include <vector>\n\ntemplate<typename T>\nstruct accumulate1D{\n  std::vector<T>\
    \ sum;\n  accumulate1D(){}\n  accumulate1D(const std::vector<T> &v){\n    sum\
    \ = v;\n    for(int i=1;i<v.size();i++) sum[i] = (sum[i-1] + v[i]);\n  }\n  T\
    \ getsum(int l, int r){\n    if(l>=r) return 0;\n    return (l==0?sum[r-1]:(sum[r-1]\
    \ - sum[l-1]));\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: 1Dquery/accumulate1D.cpp
  requiredBy: []
  timestamp: '2021-04-01 21:41:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/1Dquery/accumulate1D.test.cpp
  - verify/2Dquery/fractional_cascading_query.test.cpp
documentation_of: 1Dquery/accumulate1D.cpp
layout: document
redirect_from:
- /library/1Dquery/accumulate1D.cpp
- /library/1Dquery/accumulate1D.cpp.html
title: 1Dquery/accumulate1D.cpp
---
