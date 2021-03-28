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
  bundledCode: "#line 1 \"2Dquery/accumulate2D.cpp\"\n#include <vector>\n#include\
    \ <iostream>\n#include <functional>\n#include <cassert>\n\ntemplate<typename T>\n\
    struct accumulate2D{\n  int n, m;\n  std::vector<std::vector<T>> sum;\n  accumulate2D(){}\n\
    \  accumulate2D(const std::vector<std::vector<T>> &v){\n    assert(v.size() >\
    \ 0);\n    assert(v[0].size() > 0);\n    n = v.size(), m = v[0].size();\n    sum.resize(n,\
    \ std::vector<T>(m));\n    for(int j=0;j<m;j++){\n      for(int i=0;i<n;i++){\n\
    \        sum[i][j] = ((i==0?0:sum[i-1][j]) + v[i][j]);\n      }\n    }\n    for(int\
    \ i=0;i<n;i++){\n      for(int j=0;j<m;j++){\n        sum[i][j] = (sum[i][j] +\
    \ (j==0?0:sum[i][j-1]));\n      }\n    }\n  }\n  T query(int lx, int rx, int ly,\
    \ int ry){\n    lx = std::max(0, lx);\n    rx = std::min(n, rx);\n    ly = std::max(0,\
    \ ly);\n    ry = std::min(n, ry);\n    if(lx > rx || ly > ry) return 0;\n    T\
    \ upper_left = (lx==0||ly==0?0:sum[lx-1][ly-1]);\n    T lower_left = (rx==0||ly==0?0:sum[rx-1][ly-1]);\n\
    \    T upper_right = (lx==0||ry==0?0:sum[lx-1][ry-1]);\n    T lower_right = (rx==0||ry==0?0:sum[rx-1][ry-1]);\n\
    \    return ((upper_left + lower_right) - (lower_left + upper_right));\n  }\n\
    };\n"
  code: "#include <vector>\n#include <iostream>\n#include <functional>\n#include <cassert>\n\
    \ntemplate<typename T>\nstruct accumulate2D{\n  int n, m;\n  std::vector<std::vector<T>>\
    \ sum;\n  accumulate2D(){}\n  accumulate2D(const std::vector<std::vector<T>> &v){\n\
    \    assert(v.size() > 0);\n    assert(v[0].size() > 0);\n    n = v.size(), m\
    \ = v[0].size();\n    sum.resize(n, std::vector<T>(m));\n    for(int j=0;j<m;j++){\n\
    \      for(int i=0;i<n;i++){\n        sum[i][j] = ((i==0?0:sum[i-1][j]) + v[i][j]);\n\
    \      }\n    }\n    for(int i=0;i<n;i++){\n      for(int j=0;j<m;j++){\n    \
    \    sum[i][j] = (sum[i][j] + (j==0?0:sum[i][j-1]));\n      }\n    }\n  }\n  T\
    \ query(int lx, int rx, int ly, int ry){\n    lx = std::max(0, lx);\n    rx =\
    \ std::min(n, rx);\n    ly = std::max(0, ly);\n    ry = std::min(n, ry);\n   \
    \ if(lx > rx || ly > ry) return 0;\n    T upper_left = (lx==0||ly==0?0:sum[lx-1][ly-1]);\n\
    \    T lower_left = (rx==0||ly==0?0:sum[rx-1][ly-1]);\n    T upper_right = (lx==0||ry==0?0:sum[lx-1][ry-1]);\n\
    \    T lower_right = (rx==0||ry==0?0:sum[rx-1][ry-1]);\n    return ((upper_left\
    \ + lower_right) - (lower_left + upper_right));\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: 2Dquery/accumulate2D.cpp
  requiredBy: []
  timestamp: '2021-03-29 02:52:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: 2Dquery/accumulate2D.cpp
layout: document
redirect_from:
- /library/2Dquery/accumulate2D.cpp
- /library/2Dquery/accumulate2D.cpp.html
title: 2Dquery/accumulate2D.cpp
---
