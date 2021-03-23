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
    #include <tuple>\n#include <numeric>\n#include <cassert>\n#include <queue>\n\n\
    struct union_find_rollback{\n  std::vector<int> par, sz;\n  std::vector<std::tuple<bool,\
    \ int, int>> history;\n  std::vector<std::vector<int>> ch;\n  int component;\n\
    \n  union_find_rollback(int n):par(n), sz(n, 1), ch(n), component(n){\n    std::iota(par.begin(),\
    \ par.end(), 0);\n  }\n  int find(int u){\n    if(par[u] == u) return u;\n   \
    \ return find(par[u]);\n  }\n  int size(int u){\n    return sz[find(u)];\n  }\n\
    \  bool same(int u, int v){\n    return find(u) == find(v);\n  }\n  bool unite(int\
    \ u, int v){\n    u = find(u);\n    v = find(v);\n    if(u == v){\n      history.push_back({false,\
    \ u, u});\n      return false;\n    }\n    if(sz[v] > sz[u]) std::swap(u, v);\n\
    \    component--;\n    sz[u] += sz[v];\n    ch[u].push_back(v);\n    par[v] =\
    \ u;\n    history.push_back({true, v, u});\n    return true;\n  }\n  std::tuple<bool,\
    \ int, int> undo(){\n    assert(history.size() > 0);\n    auto [q, c, p] = history.back();\n\
    \    history.pop_back();\n    if(q==false) return {q, c, p};\n    component++;\n\
    \    par[c] = c;\n    sz[p] -= sz[c];\n    ch[p].pop_back();\n    return {q, c,\
    \ p};\n  }\n  std::vector<int> enumerate(int u){\n    std::vector<int> ret;\n\
    \    std::queue<int> q;\n    q.push(find(u));\n    while(!q.empty()){\n      int\
    \ v = q.front();\n      q.pop();\n      ret.push_back(v);\n      for(int c:ch[v])\
    \ q.push(c);\n    }\n    return ret;\n  }\n  int count_connected_component(){\n\
    \    return component;\n  }\n};\n"
  code: "#include <vector>\n#include <tuple>\n#include <numeric>\n#include <cassert>\n\
    #include <queue>\n\nstruct union_find_rollback{\n  std::vector<int> par, sz;\n\
    \  std::vector<std::tuple<bool, int, int>> history;\n  std::vector<std::vector<int>>\
    \ ch;\n  int component;\n\n  union_find_rollback(int n):par(n), sz(n, 1), ch(n),\
    \ component(n){\n    std::iota(par.begin(), par.end(), 0);\n  }\n  int find(int\
    \ u){\n    if(par[u] == u) return u;\n    return find(par[u]);\n  }\n  int size(int\
    \ u){\n    return sz[find(u)];\n  }\n  bool same(int u, int v){\n    return find(u)\
    \ == find(v);\n  }\n  bool unite(int u, int v){\n    u = find(u);\n    v = find(v);\n\
    \    if(u == v){\n      history.push_back({false, u, u});\n      return false;\n\
    \    }\n    if(sz[v] > sz[u]) std::swap(u, v);\n    component--;\n    sz[u] +=\
    \ sz[v];\n    ch[u].push_back(v);\n    par[v] = u;\n    history.push_back({true,\
    \ v, u});\n    return true;\n  }\n  std::tuple<bool, int, int> undo(){\n    assert(history.size()\
    \ > 0);\n    auto [q, c, p] = history.back();\n    history.pop_back();\n    if(q==false)\
    \ return {q, c, p};\n    component++;\n    par[c] = c;\n    sz[p] -= sz[c];\n\
    \    ch[p].pop_back();\n    return {q, c, p};\n  }\n  std::vector<int> enumerate(int\
    \ u){\n    std::vector<int> ret;\n    std::queue<int> q;\n    q.push(find(u));\n\
    \    while(!q.empty()){\n      int v = q.front();\n      q.pop();\n      ret.push_back(v);\n\
    \      for(int c:ch[v]) q.push(c);\n    }\n    return ret;\n  }\n  int count_connected_component(){\n\
    \    return component;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: union_find/union_find_rollback.cpp
  requiredBy: []
  timestamp: '2021-03-23 22:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: union_find/union_find_rollback.cpp
layout: document
redirect_from:
- /library/union_find/union_find_rollback.cpp
- /library/union_find/union_find_rollback.cpp.html
title: union_find/union_find_rollback.cpp
---
