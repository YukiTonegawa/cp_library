---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: 1Dquery/accumulate1D.cpp
    title: 1Dquery/accumulate1D.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"2Dquery/fractional_cascading_query.cpp\"\n#include <vector>\n\
    #include <tuple>\n#include <algorithm>\n#include <numeric>\n#include <array>\n\
    #line 2 \"1Dquery/accumulate1D.cpp\"\n\ntemplate<typename T>\nstruct accumulate1D{\n\
    \  std::vector<T> sum;\n  accumulate1D(){}\n  accumulate1D(const std::vector<T>\
    \ &v){\n    sum = v;\n    for(int i=1;i<v.size();i++) sum[i] = (sum[i-1] + v[i]);\n\
    \  }\n  T query(int l, int r){\n    if(l>=r) return 0;\n    return (l==0?sum[r-1]:(sum[r-1]\
    \ - sum[l-1]));\n  }\n};\n#line 7 \"2Dquery/fractional_cascading_query.cpp\"\n\
    \ntemplate<typename T, typename Idx = int>\nstruct fractional_cascading_query{\n\
    \  using point = std::tuple<Idx, Idx, T>;\n\n  using ds = accumulate1D<T>;\n \
    \ T z = 0;\n  const std::function<T(T, T)> f = [](T a, T b){return a + b;};\n\
    \  \n  std::vector<Idx> x, y;\n  std::vector<point> p;\n  struct node{\n    std::pair<int,\
    \ int> x_range;\n    node *ch[2];\n    std::vector<int> list;\n    std::vector<std::array<int,\
    \ 4>> next_idx;\n    ds _ds;\n    node(){ch[0] = ch[1] = nullptr;}\n  };\n  node\
    \ *root;\n  void build(node *v, int l, int r){\n    std::vector<T> value_list(v->list.size());\n\
    \    for(int i=0;i<v->list.size();i++) value_list[i] = std::get<2>(p[v->list[i]]);\n\
    \    v->_ds = ds(value_list);\n    if(r-l<2) return;\n    int mid = (l+r)/2;\n\
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
    \ std::make_pair(0, x.size());\n    build(root, 0, x.size());\n  }\n  T query(node\
    \ *v, Idx lx, Idx rx, int ly, int ry){\n    Idx a = x[v->x_range.first], b = x[v->x_range.second-1];\n\
    \    if(!v || rx <= a || b < lx || lx >= rx || ly >= ry) return z;\n    if(lx\
    \ <= a && b < rx) return v->_ds.query(ly, ry);\n    return f(query(v->ch[0], lx,\
    \ rx, v->next_idx[ly][1], v->next_idx[ry-1][0]),\n             query(v->ch[1],\
    \ lx, rx, v->next_idx[ly][3], v->next_idx[ry-1][2]));\n  }\n  T query(Idx lx,\
    \ Idx rx, Idx ly, Idx ry){\n    int ly_idx = std::lower_bound(y.begin(), y.end(),\
    \ ly) - y.begin();\n    int ry_idx = std::lower_bound(y.begin(), y.end(), ry)\
    \ - y.begin();\n    return query(root, lx, rx, ly_idx, ry_idx);\n  }\n};\n"
  code: "#include <vector>\n#include <tuple>\n#include <algorithm>\n#include <numeric>\n\
    #include <array>\n#include \"../1Dquery/accumulate1D.cpp\"\n\ntemplate<typename\
    \ T, typename Idx = int>\nstruct fractional_cascading_query{\n  using point =\
    \ std::tuple<Idx, Idx, T>;\n\n  using ds = accumulate1D<T>;\n  T z = 0;\n  const\
    \ std::function<T(T, T)> f = [](T a, T b){return a + b;};\n  \n  std::vector<Idx>\
    \ x, y;\n  std::vector<point> p;\n  struct node{\n    std::pair<int, int> x_range;\n\
    \    node *ch[2];\n    std::vector<int> list;\n    std::vector<std::array<int,\
    \ 4>> next_idx;\n    ds _ds;\n    node(){ch[0] = ch[1] = nullptr;}\n  };\n  node\
    \ *root;\n  void build(node *v, int l, int r){\n    std::vector<T> value_list(v->list.size());\n\
    \    for(int i=0;i<v->list.size();i++) value_list[i] = std::get<2>(p[v->list[i]]);\n\
    \    v->_ds = ds(value_list);\n    if(r-l<2) return;\n    int mid = (l+r)/2;\n\
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
    \ std::make_pair(0, x.size());\n    build(root, 0, x.size());\n  }\n  T query(node\
    \ *v, Idx lx, Idx rx, int ly, int ry){\n    Idx a = x[v->x_range.first], b = x[v->x_range.second-1];\n\
    \    if(!v || rx <= a || b < lx || lx >= rx || ly >= ry) return z;\n    if(lx\
    \ <= a && b < rx) return v->_ds.query(ly, ry);\n    return f(query(v->ch[0], lx,\
    \ rx, v->next_idx[ly][1], v->next_idx[ry-1][0]),\n             query(v->ch[1],\
    \ lx, rx, v->next_idx[ly][3], v->next_idx[ry-1][2]));\n  }\n  T query(Idx lx,\
    \ Idx rx, Idx ly, Idx ry){\n    int ly_idx = std::lower_bound(y.begin(), y.end(),\
    \ ly) - y.begin();\n    int ry_idx = std::lower_bound(y.begin(), y.end(), ry)\
    \ - y.begin();\n    return query(root, lx, rx, ly_idx, ry_idx);\n  }\n};\n"
  dependsOn:
  - 1Dquery/accumulate1D.cpp
  isVerificationFile: false
  path: 2Dquery/fractional_cascading_query.cpp
  requiredBy: []
  timestamp: '2021-03-29 02:52:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: 2Dquery/fractional_cascading_query.cpp
layout: document
redirect_from:
- /library/2Dquery/fractional_cascading_query.cpp
- /library/2Dquery/fractional_cascading_query.cpp.html
title: 2Dquery/fractional_cascading_query.cpp
---
