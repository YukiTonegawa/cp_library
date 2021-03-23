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
  bundledCode: "#line 1 \"union_find/union_find.cpp\"\n#include <vector>\n#include\
    \ <iostream>\n#include <numeric>\n\nstruct union_find{\n  std::vector<int> par,\
    \ sz;\n  union_find(int n):par(n), sz(n, 1){\n    std::iota(par.begin(), par.end(),\
    \ 0);\n  }\n  int find(int u){\n    if(par[u] == u) return u;\n    return par[u]\
    \ = find(par[u]);\n  }\n  int size(int u){\n    return sz[find(u)];\n  }\n  bool\
    \ same(int u, int v){\n    return find(u) == find(v);\n  }\n  void unite(int u,\
    \ int v){\n    u = find(u);\n    v = find(v);\n    if(u == v) return;\n    if(sz[v]\
    \ > sz[u]) std::swap(u, v);\n    sz[u] += sz[v];\n    par[v] = u;\n  }\n};\n"
  code: "#include <vector>\n#include <iostream>\n#include <numeric>\n\nstruct union_find{\n\
    \  std::vector<int> par, sz;\n  union_find(int n):par(n), sz(n, 1){\n    std::iota(par.begin(),\
    \ par.end(), 0);\n  }\n  int find(int u){\n    if(par[u] == u) return u;\n   \
    \ return par[u] = find(par[u]);\n  }\n  int size(int u){\n    return sz[find(u)];\n\
    \  }\n  bool same(int u, int v){\n    return find(u) == find(v);\n  }\n  void\
    \ unite(int u, int v){\n    u = find(u);\n    v = find(v);\n    if(u == v) return;\n\
    \    if(sz[v] > sz[u]) std::swap(u, v);\n    sz[u] += sz[v];\n    par[v] = u;\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: union_find/union_find.cpp
  requiredBy: []
  timestamp: '2021-03-23 22:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: union_find/union_find.cpp
layout: document
redirect_from:
- /library/union_find/union_find.cpp
- /library/union_find/union_find.cpp.html
title: union_find/union_find.cpp
---
