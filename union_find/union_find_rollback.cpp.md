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
  bundledCode: "#line 1 \"union_find/union_find_rollback.cpp\"\n#include <vector>\n\
    #include <tuple>\n#include <numeric>\n#include <cassert>\n\nstruct union_find_rollback{\n\
    \  std::vector<int> par, sz;\n  std::vector<std::tuple<bool, int, int>> history;\n\
    \n  union_find_rollback(int n):par(n), sz(n, 1){\n    std::iota(par.begin(), par.end(),\
    \ 0);\n  }\n  int find(int u){\n    if(par[u] == u) return u;\n    return find(par[u]);\n\
    \  }\n  int size(int u){\n    return sz[find(u)];\n  }\n  bool same(int u, int\
    \ v){\n    return find(u) == find(v);\n  }\n  bool unite(int u, int v){\n    u\
    \ = find(u);\n    v = find(v);\n    if(u == v){\n      history.push_back({false,\
    \ u, u});\n      return false;\n    }\n    if(sz[v] > sz[u]) std::swap(u, v);\n\
    \    sz[u] += sz[v];\n    par[v] = u;\n    history.push_back({true, v, u});\n\
    \    return true;\n  }\n  std::tuple<bool, int, int> undo(){\n    assert(history.size()\
    \ > 0);\n    auto [q, c, p] = history.back();\n    history.pop_back();\n    if(q==false)\
    \ return {q, c, p};\n    par[c] = c;\n    sz[p] -= sz[c];\n    return {q, c, p};\n\
    \  }\n};\n"
  code: "#include <vector>\n#include <tuple>\n#include <numeric>\n#include <cassert>\n\
    \nstruct union_find_rollback{\n  std::vector<int> par, sz;\n  std::vector<std::tuple<bool,\
    \ int, int>> history;\n\n  union_find_rollback(int n):par(n), sz(n, 1){\n    std::iota(par.begin(),\
    \ par.end(), 0);\n  }\n  int find(int u){\n    if(par[u] == u) return u;\n   \
    \ return find(par[u]);\n  }\n  int size(int u){\n    return sz[find(u)];\n  }\n\
    \  bool same(int u, int v){\n    return find(u) == find(v);\n  }\n  bool unite(int\
    \ u, int v){\n    u = find(u);\n    v = find(v);\n    if(u == v){\n      history.push_back({false,\
    \ u, u});\n      return false;\n    }\n    if(sz[v] > sz[u]) std::swap(u, v);\n\
    \    sz[u] += sz[v];\n    par[v] = u;\n    history.push_back({true, v, u});\n\
    \    return true;\n  }\n  std::tuple<bool, int, int> undo(){\n    assert(history.size()\
    \ > 0);\n    auto [q, c, p] = history.back();\n    history.pop_back();\n    if(q==false)\
    \ return {q, c, p};\n    par[c] = c;\n    sz[p] -= sz[c];\n    return {q, c, p};\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: union_find/union_find_rollback.cpp
  requiredBy: []
  timestamp: '2021-03-23 19:56:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: union_find/union_find_rollback.cpp
layout: document
redirect_from:
- /library/union_find/union_find_rollback.cpp
- /library/union_find/union_find_rollback.cpp.html
title: union_find/union_find_rollback.cpp
---
