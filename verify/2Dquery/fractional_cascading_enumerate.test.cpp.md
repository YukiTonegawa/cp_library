---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: 2Dquery/fractional_cascading_enumerate.cpp
    title: 2Dquery/fractional_cascading_enumerate.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C
  bundledCode: "#line 1 \"verify/2Dquery/fractional_cascading_enumerate.test.cpp\"\
    \n#include <iostream>\n#include <tuple>\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C\"\
    \n#line 1 \"2Dquery/fractional_cascading_enumerate.cpp\"\n#include <vector>\n\
    #line 3 \"2Dquery/fractional_cascading_enumerate.cpp\"\n#include <algorithm>\n\
    #include <numeric>\n#include <array>\n\ntemplate<typename T, typename Idx = int>\n\
    struct fractional_cascading_enumerate{\nprivate:\n  using point = std::tuple<Idx,\
    \ Idx, T>;\n  std::vector<Idx> x, y;\n  std::vector<point> p;\n  struct node{\n\
    \    std::pair<int, int> x_range;\n    node *ch[2];\n    std::vector<std::array<int,\
    \ 5>> info;\n    node(){ch[0] = ch[1] = nullptr;}\n  };\n  node *root;\n  void\
    \ build(node *v, int l, int r){\n    if(r-l<2) return;\n    int mid = (l+r)/2;\n\
    \    Idx split_x = x[mid];\n    v->ch[0] = new node();\n    v->ch[1] = new node();\n\
    \    v->ch[0]->x_range = std::make_pair(l, mid);\n    v->ch[1]->x_range = std::make_pair(mid,\
    \ r);\n    int lsz = 0, rsz = 0;\n    for(int i=0;i<v->info.size();i++){\n   \
    \   int p_idx = v->info[i][4];\n      if(std::get<0>(p[p_idx]) < split_x){\n \
    \       v->info[i][0] = lsz + 1;\n        v->info[i][1] = lsz;\n        v->info[i][2]\
    \ = v->info[i][3] = rsz;\n        v->ch[0]->info.push_back({-1, -1, -1, -1, p_idx});\n\
    \        lsz++;\n      }else{\n        v->info[i][0] = v->info[i][1] = lsz;\n\
    \        v->info[i][2] = rsz + 1;\n        v->info[i][3] = rsz;\n        v->ch[1]->info.push_back({-1,\
    \ -1, -1, -1, p_idx});\n        rsz++;\n      }\n    }\n    build(v->ch[0], l,\
    \ mid);\n    build(v->ch[1], mid, r);\n  }\npublic:\n  void build(const std::vector<point>\
    \ &points){\n    p = points;\n    root = new node();\n    std::sort(p.begin(),\
    \ p.end(), [](point &A, point &B){\n      return std::get<1>(A) < std::get<1>(B);\n\
    \    });\n    for(int i=0;i<p.size();i++){\n      x.push_back(std::get<0>(p[i]));\n\
    \      y.push_back(std::get<1>(p[i]));\n    }\n    std::sort(x.begin(), x.end());\n\
    \    x.erase(std::unique(x.begin(), x.end()), x.end());\n    root->info.resize(p.size());\n\
    \    for(int i=0;i<p.size();i++) root->info[i] = {-1, -1, -1, -1, i};\n    root->x_range\
    \ = std::make_pair(0, x.size());\n    build(root, 0, x.size());\n  }\n  fractional_cascading_enumerate(const\
    \ std::vector<point> &points){\n    build(points);\n  }\n  void query(node *v,\
    \ Idx lx, Idx rx, int ly, int ry, std::vector<point> &ret){\n    Idx a = x[v->x_range.first],\
    \ b = x[v->x_range.second-1];\n    if(!v || rx <= a || b < lx || ly >= ry) return;\n\
    \    if(lx <= a && b < rx){\n      for(int i=ly;i<ry;i++) ret.push_back(p[v->info[i][4]]);\n\
    \      return;\n    }\n    query(v->ch[0], lx, rx, v->info[ly][1], v->info[ry-1][0],\
    \ ret);\n    query(v->ch[1], lx, rx, v->info[ly][3], v->info[ry-1][2], ret);\n\
    \  }\n  std::vector<point> query(Idx lx, Idx rx, Idx ly, Idx ry){\n    if(lx >=\
    \ rx || ly >= ry) return {};\n    int ly_idx = std::lower_bound(y.begin(), y.end(),\
    \ ly) - y.begin();\n    int ry_idx = std::lower_bound(y.begin(), y.end(), ry)\
    \ - y.begin();\n    std::vector<point> ret;\n    query(root, lx, rx, ly_idx, ry_idx,\
    \ ret);\n    return ret;\n  }\n};\n#line 5 \"verify/2Dquery/fractional_cascading_enumerate.test.cpp\"\
    \n\n\n#line 8 \"verify/2Dquery/fractional_cascading_enumerate.test.cpp\"\nint\
    \ main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n  int\
    \ n;\n  std::cin >> n;\n  std::vector<std::tuple<int, int, int>> v(n);\n  int\
    \ shift = 1000000000;\n  for(int i=0;i<n;i++){\n    int x, y;\n    std::cin >>\
    \ x >> y;\n    v[i] = std::make_tuple(x + shift, y + shift, i);\n  }\n  fractional_cascading_enumerate<int,\
    \ int> rect(v);\n  int q;std::cin >> q;\n  for(int i=0;i<q;i++){\n    int lx,\
    \ rx, ly, ry;\n    std::cin >> lx >> rx >> ly >> ry;\n    auto P = rect.query(lx\
    \ + shift, rx + shift + 1, ly + shift, ry + shift + 1);\n    std::vector<int>\
    \ ans;\n    for(auto [_, __, idx] : P) ans.push_back(idx);\n    std::sort(ans.begin(),\
    \ ans.end());\n    for(int idx:ans) std::cout << idx << '\\n';\n    std::cout\
    \ << '\\n';\n  }\n}\n"
  code: "#include <iostream>\n#include <tuple>\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C\"\
    \n#include \"../../2Dquery/fractional_cascading_enumerate.cpp\"\n\n\n#include\
    \ <iostream>\nint main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \  int n;\n  std::cin >> n;\n  std::vector<std::tuple<int, int, int>> v(n);\n\
    \  int shift = 1000000000;\n  for(int i=0;i<n;i++){\n    int x, y;\n    std::cin\
    \ >> x >> y;\n    v[i] = std::make_tuple(x + shift, y + shift, i);\n  }\n  fractional_cascading_enumerate<int,\
    \ int> rect(v);\n  int q;std::cin >> q;\n  for(int i=0;i<q;i++){\n    int lx,\
    \ rx, ly, ry;\n    std::cin >> lx >> rx >> ly >> ry;\n    auto P = rect.query(lx\
    \ + shift, rx + shift + 1, ly + shift, ry + shift + 1);\n    std::vector<int>\
    \ ans;\n    for(auto [_, __, idx] : P) ans.push_back(idx);\n    std::sort(ans.begin(),\
    \ ans.end());\n    for(int idx:ans) std::cout << idx << '\\n';\n    std::cout\
    \ << '\\n';\n  }\n}\n"
  dependsOn:
  - 2Dquery/fractional_cascading_enumerate.cpp
  isVerificationFile: true
  path: verify/2Dquery/fractional_cascading_enumerate.test.cpp
  requiredBy: []
  timestamp: '2021-04-03 04:32:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/2Dquery/fractional_cascading_enumerate.test.cpp
layout: document
redirect_from:
- /verify/verify/2Dquery/fractional_cascading_enumerate.test.cpp
- /verify/verify/2Dquery/fractional_cascading_enumerate.test.cpp.html
title: verify/2Dquery/fractional_cascading_enumerate.test.cpp
---
