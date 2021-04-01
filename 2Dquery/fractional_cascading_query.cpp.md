---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/2Dquery/fractional_cascading_query.test.cpp
    title: verify/2Dquery/fractional_cascading_query.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"2Dquery/fractional_cascading_query.cpp\"\n#include <vector>\n\
    #include <tuple>\n#include <algorithm>\n#include <numeric>\n#include <array>\n\
    \ntemplate<typename Val, typename Idx, typename Container,\n  Val (*id)(),\n \
    \ Val (*merge)(Val, Val),\n  Val (*query1d)(Container&, int, int),\n  Container\
    \ (*make_container)(std::vector<Val>&)\n>\nstruct fractional_cascading_query{\n\
    \  using point = std::tuple<Idx, Idx, Val>;\n  std::vector<Idx> x, y;\n  std::vector<point>\
    \ p;\n  struct node{\n    std::pair<int, int> x_range;\n    node *ch[2];\n   \
    \ std::vector<int> list;\n    std::vector<std::array<int, 4>> next_idx;\n    Container\
    \ _ds;\n    node(){ch[0] = ch[1] = nullptr;}\n  };\n  node *root;\n  void build(node\
    \ *v, int l, int r){\n    std::vector<Val> value_list(v->list.size());\n    for(int\
    \ i=0;i<v->list.size();i++) value_list[i] = std::get<2>(p[v->list[i]]);\n    v->_ds\
    \ = make_container(value_list);\n    if(r-l<2) return;\n    int mid = (l+r)/2;\n\
    \    Idx split_x = x[mid];\n    v->ch[0] = new node();\n    v->ch[1] = new node();\n\
    \    v->ch[0]->x_range = std::make_pair(l, mid);\n    v->ch[1]->x_range = std::make_pair(mid,\
    \ r);\n    int lsz = 0, rsz = 0;\n    for(int p_idx:v->list){\n      if(std::get<0>(p[p_idx])\
    \ < split_x){\n        v->next_idx.push_back(std::array<int, 4>{lsz+1, lsz, rsz,\
    \ rsz});\n        v->ch[0]->list.push_back(p_idx);\n        lsz++;\n      }else{\n\
    \        v->next_idx.push_back(std::array<int, 4>{lsz, lsz, rsz+1, rsz});\n  \
    \      v->ch[1]->list.push_back(p_idx);\n        rsz++;\n      }\n    }\n    build(v->ch[0],\
    \ l, mid);\n    build(v->ch[1], mid, r);\n  }\n  fractional_cascading_query(const\
    \ std::vector<point> &points){\n    p = points;\n    root = new node();\n    std::sort(p.begin(),\
    \ p.end(), [](point &A, point &B){\n      return std::get<1>(A) < std::get<1>(B);\n\
    \    });\n    for(int i=0;i<p.size();i++){\n      x.push_back(std::get<0>(p[i]));\n\
    \      y.push_back(std::get<1>(p[i]));\n    }\n    std::sort(x.begin(), x.end());\n\
    \    x.erase(std::unique(x.begin(), x.end()), x.end());\n    root->list.resize(p.size());\n\
    \    std::iota(root->list.begin(), root->list.end(), 0);\n    root->x_range =\
    \ std::make_pair(0, x.size());\n    build(root, 0, x.size());\n  }\n  Val query(node\
    \ *v, Idx lx, Idx rx, int ly, int ry){\n    Idx a = x[v->x_range.first], b = x[v->x_range.second-1];\n\
    \    if(!v || rx <= a || b < lx || lx >= rx || ly >= ry) return id();\n    if(lx\
    \ <= a && b < rx) return query1d(v->_ds, ly, ry);\n    return merge(query(v->ch[0],\
    \ lx, rx, v->next_idx[ly][1], v->next_idx[ry-1][0]),\n             query(v->ch[1],\
    \ lx, rx, v->next_idx[ly][3], v->next_idx[ry-1][2]));\n  }\n  Val query(Idx lx,\
    \ Idx rx, Idx ly, Idx ry){\n    int ly_idx = std::lower_bound(y.begin(), y.end(),\
    \ ly) - y.begin();\n    int ry_idx = std::lower_bound(y.begin(), y.end(), ry)\
    \ - y.begin();\n    return query(root, lx, rx, ly_idx, ry_idx);\n  }\n};\n"
  code: "#include <vector>\n#include <tuple>\n#include <algorithm>\n#include <numeric>\n\
    #include <array>\n\ntemplate<typename Val, typename Idx, typename Container,\n\
    \  Val (*id)(),\n  Val (*merge)(Val, Val),\n  Val (*query1d)(Container&, int,\
    \ int),\n  Container (*make_container)(std::vector<Val>&)\n>\nstruct fractional_cascading_query{\n\
    \  using point = std::tuple<Idx, Idx, Val>;\n  std::vector<Idx> x, y;\n  std::vector<point>\
    \ p;\n  struct node{\n    std::pair<int, int> x_range;\n    node *ch[2];\n   \
    \ std::vector<int> list;\n    std::vector<std::array<int, 4>> next_idx;\n    Container\
    \ _ds;\n    node(){ch[0] = ch[1] = nullptr;}\n  };\n  node *root;\n  void build(node\
    \ *v, int l, int r){\n    std::vector<Val> value_list(v->list.size());\n    for(int\
    \ i=0;i<v->list.size();i++) value_list[i] = std::get<2>(p[v->list[i]]);\n    v->_ds\
    \ = make_container(value_list);\n    if(r-l<2) return;\n    int mid = (l+r)/2;\n\
    \    Idx split_x = x[mid];\n    v->ch[0] = new node();\n    v->ch[1] = new node();\n\
    \    v->ch[0]->x_range = std::make_pair(l, mid);\n    v->ch[1]->x_range = std::make_pair(mid,\
    \ r);\n    int lsz = 0, rsz = 0;\n    for(int p_idx:v->list){\n      if(std::get<0>(p[p_idx])\
    \ < split_x){\n        v->next_idx.push_back(std::array<int, 4>{lsz+1, lsz, rsz,\
    \ rsz});\n        v->ch[0]->list.push_back(p_idx);\n        lsz++;\n      }else{\n\
    \        v->next_idx.push_back(std::array<int, 4>{lsz, lsz, rsz+1, rsz});\n  \
    \      v->ch[1]->list.push_back(p_idx);\n        rsz++;\n      }\n    }\n    build(v->ch[0],\
    \ l, mid);\n    build(v->ch[1], mid, r);\n  }\n  fractional_cascading_query(const\
    \ std::vector<point> &points){\n    p = points;\n    root = new node();\n    std::sort(p.begin(),\
    \ p.end(), [](point &A, point &B){\n      return std::get<1>(A) < std::get<1>(B);\n\
    \    });\n    for(int i=0;i<p.size();i++){\n      x.push_back(std::get<0>(p[i]));\n\
    \      y.push_back(std::get<1>(p[i]));\n    }\n    std::sort(x.begin(), x.end());\n\
    \    x.erase(std::unique(x.begin(), x.end()), x.end());\n    root->list.resize(p.size());\n\
    \    std::iota(root->list.begin(), root->list.end(), 0);\n    root->x_range =\
    \ std::make_pair(0, x.size());\n    build(root, 0, x.size());\n  }\n  Val query(node\
    \ *v, Idx lx, Idx rx, int ly, int ry){\n    Idx a = x[v->x_range.first], b = x[v->x_range.second-1];\n\
    \    if(!v || rx <= a || b < lx || lx >= rx || ly >= ry) return id();\n    if(lx\
    \ <= a && b < rx) return query1d(v->_ds, ly, ry);\n    return merge(query(v->ch[0],\
    \ lx, rx, v->next_idx[ly][1], v->next_idx[ry-1][0]),\n             query(v->ch[1],\
    \ lx, rx, v->next_idx[ly][3], v->next_idx[ry-1][2]));\n  }\n  Val query(Idx lx,\
    \ Idx rx, Idx ly, Idx ry){\n    int ly_idx = std::lower_bound(y.begin(), y.end(),\
    \ ly) - y.begin();\n    int ry_idx = std::lower_bound(y.begin(), y.end(), ry)\
    \ - y.begin();\n    return query(root, lx, rx, ly_idx, ry_idx);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: 2Dquery/fractional_cascading_query.cpp
  requiredBy: []
  timestamp: '2021-04-01 21:41:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/2Dquery/fractional_cascading_query.test.cpp
documentation_of: 2Dquery/fractional_cascading_query.cpp
layout: document
redirect_from:
- /library/2Dquery/fractional_cascading_query.cpp
- /library/2Dquery/fractional_cascading_query.cpp.html
title: 2Dquery/fractional_cascading_query.cpp
---
