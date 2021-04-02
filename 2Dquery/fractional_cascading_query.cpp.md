---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/2Dquery/fractional_cascading_query.test.cpp
    title: verify/2Dquery/fractional_cascading_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/2Dquery/fractional_cascading_query_update.test.cpp
    title: verify/2Dquery/fractional_cascading_query_update.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"2Dquery/fractional_cascading_query.cpp\"\n#include <vector>\n\
    #include <tuple>\n#include <algorithm>\n#include <numeric>\n#include <array>\n\
    \ntemplate<typename Val, typename Idx, typename Container,\n  Val (*id)(),\n \
    \ Val (*merge)(Val, Val),\n  Val (*query1d)(Container&, int, int),\n  void (*update1d)(Container&,\
    \ int, Val),\n  Container (*make_container)(std::vector<Val>&)\n>\nstruct fractional_cascading_query{\n\
    \  using input_point = std::tuple<Idx, Idx, Val>;\n  using point = std::tuple<Idx,\
    \ Idx, Val, int>;\n  std::vector<Idx> x, y;\n  std::vector<point> p;\n  std::vector<int>\
    \ sorted_index, rev_index;\n  std::vector<std::vector<int>> kth_index;\n  struct\
    \ node{\n    std::pair<int, int> x_range;\n    node *ch[2];\n    std::vector<std::array<int,\
    \ 5>> info;\n    Container _ds;\n    node(){ch[0] = ch[1] = nullptr;}\n  };\n\
    \  node *root;\n  void build(node *v, int l, int r, int dep = 0){\n    if(kth_index.size()\
    \ == dep) kth_index.push_back(std::vector<int>(p.size()));\n    std::vector<Val>\
    \ value_list(v->info.size());\n    for(int i=0;i<v->info.size();i++) value_list[i]\
    \ = std::get<2>(p[v->info[i][4]]);\n    v->_ds = make_container(value_list);\n\
    \    if(r-l<2) return;\n    int mid = (l+r)/2;\n    Idx split_x = x[mid];\n  \
    \  v->ch[0] = new node();\n    v->ch[1] = new node();\n    v->ch[0]->x_range =\
    \ std::make_pair(l, mid);\n    v->ch[1]->x_range = std::make_pair(mid, r);\n \
    \   int lsz = 0, rsz = 0;\n    for(int i=0;i<v->info.size();i++){\n      int p_idx\
    \ = v->info[i][4];\n      if(std::get<0>(p[p_idx]) < split_x){\n        v->info[i][0]\
    \ = lsz + 1;\n        v->info[i][1] = lsz;\n        v->info[i][2] = v->info[i][3]\
    \ = rsz;\n        kth_index[dep][p_idx] = lsz;\n        v->ch[0]->info.push_back({-1,\
    \ -1, -1, -1, p_idx});\n        lsz++;\n      }else{\n        v->info[i][0] =\
    \ v->info[i][1] = lsz;\n        v->info[i][2] = rsz + 1;\n        v->info[i][3]\
    \ = rsz;\n        kth_index[dep][p_idx] = rsz;\n        v->ch[1]->info.push_back({-1,\
    \ -1, -1, -1, p_idx});\n        rsz++;\n      }\n    }\n    build(v->ch[0], l,\
    \ mid, dep + 1);\n    build(v->ch[1], mid, r, dep + 1);\n  }\n  fractional_cascading_query(const\
    \ std::vector<input_point> &points){\n    p.resize(points.size());\n    int i\
    \ = 0;\n    for(auto [x, y, v] : points){\n      p[i] = std::make_tuple(x, y,\
    \ v, i);\n      i++;\n    }\n    root = new node();\n    std::sort(p.begin(),\
    \ p.end(), [](point &A, point &B){\n      return std::get<1>(A) < std::get<1>(B);\n\
    \    });\n    sorted_index.resize(p.size());\n    rev_index.resize(p.size());\n\
    \    for(int i=0;i<p.size();i++){\n      x.push_back(std::get<0>(p[i]));\n   \
    \   y.push_back(std::get<1>(p[i]));\n      sorted_index[std::get<3>(p[i])] = i;\n\
    \      rev_index[i] = std::get<3>(p[i]);\n    }\n    std::sort(x.begin(), x.end());\n\
    \    x.erase(std::unique(x.begin(), x.end()), x.end());\n    root->info.resize(p.size());\n\
    \    for(int i=0;i<p.size();i++) root->info[i] = {-1, -1, -1, -1, i};\n    root->x_range\
    \ = std::make_pair(0, x.size());\n    build(root, 0, x.size());\n  }\n  Val query(node\
    \ *v, Idx lx, Idx rx, int ly, int ry){\n    Idx a = x[v->x_range.first], b = x[v->x_range.second-1];\n\
    \    if(!v || rx <= a || b < lx || ly >= ry) return id();\n    if(lx <= a && b\
    \ < rx) return query1d(v->_ds, ly, ry);\n    return merge(query(v->ch[0], lx,\
    \ rx, v->info[ly][1], v->info[ry-1][0]),\n             query(v->ch[1], lx, rx,\
    \ v->info[ly][3], v->info[ry-1][2]));\n  }\n  Val query(Idx lx, Idx rx, Idx ly,\
    \ Idx ry){\n    if(lx >= rx || ly >= ry) return id();\n    int ly_idx = std::lower_bound(y.begin(),\
    \ y.end(), ly) - y.begin();\n    int ry_idx = std::lower_bound(y.begin(), y.end(),\
    \ ry) - y.begin();\n    return query(root, lx, rx, ly_idx, ry_idx);\n  }\n  std::pair<int,\
    \ int> find(node *v, Idx _x, int ly, int ry){\n    Idx a = x[v->x_range.first],\
    \ b = x[v->x_range.second-1];\n    if(!v || _x < a || b < _x || ly >= ry) return\
    \ {0, -1};\n    if(_x <= a && b <= _x){\n      if(ry - ly >= 1) return {ry - ly,\
    \ v->info[ly][4]};\n      else return {0, -1};\n    }\n    std::pair<int, int>\
    \ L = find(v->ch[0], _x, v->info[ly][1], v->info[ry-1][0]);\n    if(L.first !=\
    \ 0) return L;\n    return find(v->ch[1], _x, v->info[ly][3], v->info[ry-1][2]);\n\
    \  }\n  std::pair<int, int> find(Idx _x, Idx _y){\n    int ly_idx = std::lower_bound(y.begin(),\
    \ y.end(), _y) - y.begin();\n    int ry_idx = std::lower_bound(y.begin(), y.end(),\
    \ _y + 1) - y.begin();\n    auto ret = find(root, _x, ly_idx, ry_idx);\n    if(ret.first)\
    \ ret.second = rev_index[ret.second];\n    return ret;\n  }\n  void update_kth(int\
    \ k, Val val){\n    k = sorted_index[k];\n    auto [px, py, _, __] = p[k];\n \
    \   node *v = root;\n    update1d(v->_ds, k, val);\n    int l = 0, r = x.size(),\
    \ dep = 0;\n    while(r - l > 1){\n      int mid = (l + r) / 2;\n      v = v->ch[px\
    \ >= x[mid]];\n      update1d(v->_ds, kth_index[dep++][k], val);\n      if(px\
    \ >= x[mid]) l = mid;\n      else r = mid;\n    }\n  }\n};\n"
  code: "#include <vector>\n#include <tuple>\n#include <algorithm>\n#include <numeric>\n\
    #include <array>\n\ntemplate<typename Val, typename Idx, typename Container,\n\
    \  Val (*id)(),\n  Val (*merge)(Val, Val),\n  Val (*query1d)(Container&, int,\
    \ int),\n  void (*update1d)(Container&, int, Val),\n  Container (*make_container)(std::vector<Val>&)\n\
    >\nstruct fractional_cascading_query{\n  using input_point = std::tuple<Idx, Idx,\
    \ Val>;\n  using point = std::tuple<Idx, Idx, Val, int>;\n  std::vector<Idx> x,\
    \ y;\n  std::vector<point> p;\n  std::vector<int> sorted_index, rev_index;\n \
    \ std::vector<std::vector<int>> kth_index;\n  struct node{\n    std::pair<int,\
    \ int> x_range;\n    node *ch[2];\n    std::vector<std::array<int, 5>> info;\n\
    \    Container _ds;\n    node(){ch[0] = ch[1] = nullptr;}\n  };\n  node *root;\n\
    \  void build(node *v, int l, int r, int dep = 0){\n    if(kth_index.size() ==\
    \ dep) kth_index.push_back(std::vector<int>(p.size()));\n    std::vector<Val>\
    \ value_list(v->info.size());\n    for(int i=0;i<v->info.size();i++) value_list[i]\
    \ = std::get<2>(p[v->info[i][4]]);\n    v->_ds = make_container(value_list);\n\
    \    if(r-l<2) return;\n    int mid = (l+r)/2;\n    Idx split_x = x[mid];\n  \
    \  v->ch[0] = new node();\n    v->ch[1] = new node();\n    v->ch[0]->x_range =\
    \ std::make_pair(l, mid);\n    v->ch[1]->x_range = std::make_pair(mid, r);\n \
    \   int lsz = 0, rsz = 0;\n    for(int i=0;i<v->info.size();i++){\n      int p_idx\
    \ = v->info[i][4];\n      if(std::get<0>(p[p_idx]) < split_x){\n        v->info[i][0]\
    \ = lsz + 1;\n        v->info[i][1] = lsz;\n        v->info[i][2] = v->info[i][3]\
    \ = rsz;\n        kth_index[dep][p_idx] = lsz;\n        v->ch[0]->info.push_back({-1,\
    \ -1, -1, -1, p_idx});\n        lsz++;\n      }else{\n        v->info[i][0] =\
    \ v->info[i][1] = lsz;\n        v->info[i][2] = rsz + 1;\n        v->info[i][3]\
    \ = rsz;\n        kth_index[dep][p_idx] = rsz;\n        v->ch[1]->info.push_back({-1,\
    \ -1, -1, -1, p_idx});\n        rsz++;\n      }\n    }\n    build(v->ch[0], l,\
    \ mid, dep + 1);\n    build(v->ch[1], mid, r, dep + 1);\n  }\n  fractional_cascading_query(const\
    \ std::vector<input_point> &points){\n    p.resize(points.size());\n    int i\
    \ = 0;\n    for(auto [x, y, v] : points){\n      p[i] = std::make_tuple(x, y,\
    \ v, i);\n      i++;\n    }\n    root = new node();\n    std::sort(p.begin(),\
    \ p.end(), [](point &A, point &B){\n      return std::get<1>(A) < std::get<1>(B);\n\
    \    });\n    sorted_index.resize(p.size());\n    rev_index.resize(p.size());\n\
    \    for(int i=0;i<p.size();i++){\n      x.push_back(std::get<0>(p[i]));\n   \
    \   y.push_back(std::get<1>(p[i]));\n      sorted_index[std::get<3>(p[i])] = i;\n\
    \      rev_index[i] = std::get<3>(p[i]);\n    }\n    std::sort(x.begin(), x.end());\n\
    \    x.erase(std::unique(x.begin(), x.end()), x.end());\n    root->info.resize(p.size());\n\
    \    for(int i=0;i<p.size();i++) root->info[i] = {-1, -1, -1, -1, i};\n    root->x_range\
    \ = std::make_pair(0, x.size());\n    build(root, 0, x.size());\n  }\n  Val query(node\
    \ *v, Idx lx, Idx rx, int ly, int ry){\n    Idx a = x[v->x_range.first], b = x[v->x_range.second-1];\n\
    \    if(!v || rx <= a || b < lx || ly >= ry) return id();\n    if(lx <= a && b\
    \ < rx) return query1d(v->_ds, ly, ry);\n    return merge(query(v->ch[0], lx,\
    \ rx, v->info[ly][1], v->info[ry-1][0]),\n             query(v->ch[1], lx, rx,\
    \ v->info[ly][3], v->info[ry-1][2]));\n  }\n  Val query(Idx lx, Idx rx, Idx ly,\
    \ Idx ry){\n    if(lx >= rx || ly >= ry) return id();\n    int ly_idx = std::lower_bound(y.begin(),\
    \ y.end(), ly) - y.begin();\n    int ry_idx = std::lower_bound(y.begin(), y.end(),\
    \ ry) - y.begin();\n    return query(root, lx, rx, ly_idx, ry_idx);\n  }\n  std::pair<int,\
    \ int> find(node *v, Idx _x, int ly, int ry){\n    Idx a = x[v->x_range.first],\
    \ b = x[v->x_range.second-1];\n    if(!v || _x < a || b < _x || ly >= ry) return\
    \ {0, -1};\n    if(_x <= a && b <= _x){\n      if(ry - ly >= 1) return {ry - ly,\
    \ v->info[ly][4]};\n      else return {0, -1};\n    }\n    std::pair<int, int>\
    \ L = find(v->ch[0], _x, v->info[ly][1], v->info[ry-1][0]);\n    if(L.first !=\
    \ 0) return L;\n    return find(v->ch[1], _x, v->info[ly][3], v->info[ry-1][2]);\n\
    \  }\n  std::pair<int, int> find(Idx _x, Idx _y){\n    int ly_idx = std::lower_bound(y.begin(),\
    \ y.end(), _y) - y.begin();\n    int ry_idx = std::lower_bound(y.begin(), y.end(),\
    \ _y + 1) - y.begin();\n    auto ret = find(root, _x, ly_idx, ry_idx);\n    if(ret.first)\
    \ ret.second = rev_index[ret.second];\n    return ret;\n  }\n  void update_kth(int\
    \ k, Val val){\n    k = sorted_index[k];\n    auto [px, py, _, __] = p[k];\n \
    \   node *v = root;\n    update1d(v->_ds, k, val);\n    int l = 0, r = x.size(),\
    \ dep = 0;\n    while(r - l > 1){\n      int mid = (l + r) / 2;\n      v = v->ch[px\
    \ >= x[mid]];\n      update1d(v->_ds, kth_index[dep++][k], val);\n      if(px\
    \ >= x[mid]) l = mid;\n      else r = mid;\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: 2Dquery/fractional_cascading_query.cpp
  requiredBy: []
  timestamp: '2021-04-03 04:32:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/2Dquery/fractional_cascading_query_update.test.cpp
  - verify/2Dquery/fractional_cascading_query.test.cpp
documentation_of: 2Dquery/fractional_cascading_query.cpp
layout: document
redirect_from:
- /library/2Dquery/fractional_cascading_query.cpp
- /library/2Dquery/fractional_cascading_query.cpp.html
title: 2Dquery/fractional_cascading_query.cpp
---
