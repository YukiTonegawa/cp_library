---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: 2Dquery/fractional_cascading_query.cpp
    title: 2Dquery/fractional_cascading_query.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"1Dquery/accumulate1D.cpp\"\n#include <vector>\n\ntemplate<typename\
    \ T>\nstruct accumulate1D{\n  std::vector<T> sum;\n  accumulate1D(){}\n  accumulate1D(const\
    \ std::vector<T> &v){\n    sum = v;\n    for(int i=1;i<v.size();i++) sum[i] =\
    \ (sum[i-1] + v[i]);\n  }\n  T query(int l, int r){\n    if(l>=r) return 0;\n\
    \    return (l==0?sum[r-1]:(sum[r-1] - sum[l-1]));\n  }\n};\n"
  code: "#include <vector>\n\ntemplate<typename T>\nstruct accumulate1D{\n  std::vector<T>\
    \ sum;\n  accumulate1D(){}\n  accumulate1D(const std::vector<T> &v){\n    sum\
    \ = v;\n    for(int i=1;i<v.size();i++) sum[i] = (sum[i-1] + v[i]);\n  }\n  T\
    \ query(int l, int r){\n    if(l>=r) return 0;\n    return (l==0?sum[r-1]:(sum[r-1]\
    \ - sum[l-1]));\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: 1Dquery/accumulate1D.cpp
  requiredBy:
  - 2Dquery/fractional_cascading_query.cpp
  timestamp: '2021-03-29 02:52:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: 1Dquery/accumulate1D.cpp
layout: document
redirect_from:
- /library/1Dquery/accumulate1D.cpp
- /library/1Dquery/accumulate1D.cpp.html
title: 1Dquery/accumulate1D.cpp
---
