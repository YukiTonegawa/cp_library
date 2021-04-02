---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/2Dquery/fractional_cascading_enumerate.test.cpp
    title: verify/2Dquery/fractional_cascading_enumerate.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"2Dquery/fractional_cascading_enumerate.cpp\"\n#include <vector>\n\
    #include <tuple>\n#include <algorithm>\n#include <numeric>\n#include <array>\n\
    \ntemplate<typename T, typename Idx = int>\nstruct fractional_cascading_enumerate{\n\
    private:\n  using point = std::tuple<Idx, Idx, T>;\n  std::vector<Idx> x, y;\n\
    \  std::vector<point> p;\n  struct node{\n    std::pair<int, int> x_range;\n \
    \   node *ch[2];\n    std::vector<std::array<int, 5>> info;\n    node(){ch[0]\
    \ = ch[1] = nullptr;}\n  };\n  node *root;\n  void build(node *v, int l, int r){\n\
    \    if(r-l<2) return;\n    int mid = (l+r)/2;\n    Idx split_x = x[mid];\n  \
    \  v->ch[0] = new node();\n    v->ch[1] = new node();\n    v->ch[0]->x_range =\
    \ std::make_pair(l, mid);\n    v->ch[1]->x_range = std::make_pair(mid, r);\n \
    \   int lsz = 0, rsz = 0;\n    for(int i=0;i<v->info.size();i++){\n      int p_idx\
    \ = v->info[i][4];\n      if(std::get<0>(p[p_idx]) < split_x){\n        v->info[i][0]\
    \ = lsz + 1;\n        v->info[i][1] = lsz;\n        v->info[i][2] = v->info[i][3]\
    \ = rsz;\n        v->ch[0]->info.push_back({-1, -1, -1, -1, p_idx});\n       \
    \ lsz++;\n      }else{\n        v->info[i][0] = v->info[i][1] = lsz;\n       \
    \ v->info[i][2] = rsz + 1;\n        v->info[i][3] = rsz;\n        v->ch[1]->info.push_back({-1,\
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
    \ ret);\n    return ret;\n  }\n};\n"
  code: "#include <vector>\n#include <tuple>\n#include <algorithm>\n#include <numeric>\n\
    #include <array>\n\ntemplate<typename T, typename Idx = int>\nstruct fractional_cascading_enumerate{\n\
    private:\n  using point = std::tuple<Idx, Idx, T>;\n  std::vector<Idx> x, y;\n\
    \  std::vector<point> p;\n  struct node{\n    std::pair<int, int> x_range;\n \
    \   node *ch[2];\n    std::vector<std::array<int, 5>> info;\n    node(){ch[0]\
    \ = ch[1] = nullptr;}\n  };\n  node *root;\n  void build(node *v, int l, int r){\n\
    \    if(r-l<2) return;\n    int mid = (l+r)/2;\n    Idx split_x = x[mid];\n  \
    \  v->ch[0] = new node();\n    v->ch[1] = new node();\n    v->ch[0]->x_range =\
    \ std::make_pair(l, mid);\n    v->ch[1]->x_range = std::make_pair(mid, r);\n \
    \   int lsz = 0, rsz = 0;\n    for(int i=0;i<v->info.size();i++){\n      int p_idx\
    \ = v->info[i][4];\n      if(std::get<0>(p[p_idx]) < split_x){\n        v->info[i][0]\
    \ = lsz + 1;\n        v->info[i][1] = lsz;\n        v->info[i][2] = v->info[i][3]\
    \ = rsz;\n        v->ch[0]->info.push_back({-1, -1, -1, -1, p_idx});\n       \
    \ lsz++;\n      }else{\n        v->info[i][0] = v->info[i][1] = lsz;\n       \
    \ v->info[i][2] = rsz + 1;\n        v->info[i][3] = rsz;\n        v->ch[1]->info.push_back({-1,\
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
    \ ret);\n    return ret;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: 2Dquery/fractional_cascading_enumerate.cpp
  requiredBy: []
  timestamp: '2021-04-03 04:32:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/2Dquery/fractional_cascading_enumerate.test.cpp
documentation_of: 2Dquery/fractional_cascading_enumerate.cpp
layout: document
redirect_from:
- /library/2Dquery/fractional_cascading_enumerate.cpp
- /library/2Dquery/fractional_cascading_enumerate.cpp.html
title: 2Dquery/fractional_cascading_enumerate.cpp
---
