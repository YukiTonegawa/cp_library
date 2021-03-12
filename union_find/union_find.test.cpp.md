---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://old.yosupo.jp/problem/unionfind
    links:
    - https://old.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"union_find/union_find.test.cpp\"\n#include <vector>\n#include\
    \ <iostream>\n#include <numeric>\n#define PROBLEM \"https://old.yosupo.jp/problem/unionfind\"\
    \nusing namespace std;\n\nstruct union_find{\n  std::vector<int> par, sz;\n  union_find(int\
    \ n):par(n), sz(n, 1){\n    std::iota(par.begin(), par.end(), 0);\n  }\n  int\
    \ find(int u){\n    if(par[u] == u) return u;\n    return par[u] = find(par[u]);\n\
    \  }\n  int size(int u){\n    return sz[find(u)];\n  }\n  bool same(int u, int\
    \ v){\n    return find(u) == find(v);\n  }\n  void unite(int u, int v){\n    u\
    \ = find(u);\n    v = find(v);\n    if(u == v) return;\n    if(sz[v] > sz[u])\
    \ std::swap(u, v);\n    sz[u] += sz[v];\n    par[v] = u;\n  }\n};\n\nint main(){\n\
    \  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\n  int a, b, c, n, q;\n\
    \  std::cin >> n >> q;\n  union_find uf(n);\n  for(int i=0;i<q;i++){\n    std::cin\
    \ >> a >> b >> c;\n    if(a==0) uf.unite(b, c);\n    else std::cout << int(uf.same(b,\
    \ c)) << '\\n';\n  }\n}\n"
  code: "#include <vector>\n#include <iostream>\n#include <numeric>\n#define PROBLEM\
    \ \"https://old.yosupo.jp/problem/unionfind\"\nusing namespace std;\n\nstruct\
    \ union_find{\n  std::vector<int> par, sz;\n  union_find(int n):par(n), sz(n,\
    \ 1){\n    std::iota(par.begin(), par.end(), 0);\n  }\n  int find(int u){\n  \
    \  if(par[u] == u) return u;\n    return par[u] = find(par[u]);\n  }\n  int size(int\
    \ u){\n    return sz[find(u)];\n  }\n  bool same(int u, int v){\n    return find(u)\
    \ == find(v);\n  }\n  void unite(int u, int v){\n    u = find(u);\n    v = find(v);\n\
    \    if(u == v) return;\n    if(sz[v] > sz[u]) std::swap(u, v);\n    sz[u] +=\
    \ sz[v];\n    par[v] = u;\n  }\n};\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \n  int a, b, c, n, q;\n  std::cin >> n >> q;\n  union_find uf(n);\n  for(int\
    \ i=0;i<q;i++){\n    std::cin >> a >> b >> c;\n    if(a==0) uf.unite(b, c);\n\
    \    else std::cout << int(uf.same(b, c)) << '\\n';\n  }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: union_find/union_find.test.cpp
  requiredBy: []
  timestamp: '2021-03-12 22:42:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: union_find/union_find.test.cpp
layout: document
redirect_from:
- /verify/union_find/union_find.test.cpp
- /verify/union_find/union_find.test.cpp.html
title: union_find/union_find.test.cpp
---
