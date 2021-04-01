---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: 1Dquery/accumulate1D.cpp
    title: 1Dquery/accumulate1D.cpp
  - icon: ':heavy_check_mark:'
    path: 2Dquery/fractional_cascading_query.cpp
    title: 2Dquery/fractional_cascading_query.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://old.yosupo.jp/problem/rectangle_sum
    links:
    - https://old.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"verify/2Dquery/fractional_cascading_query.test.cpp\"\n#include\
    \ <vector>\n#include <tuple>\n#include <algorithm>\n#include <numeric>\n#include\
    \ <array>\n#line 2 \"1Dquery/accumulate1D.cpp\"\n\ntemplate<typename T>\nstruct\
    \ accumulate1D{\n  std::vector<T> sum;\n  accumulate1D(){}\n  accumulate1D(const\
    \ std::vector<T> &v){\n    sum = v;\n    for(int i=1;i<v.size();i++) sum[i] =\
    \ (sum[i-1] + v[i]);\n  }\n  T getsum(int l, int r){\n    if(l>=r) return 0;\n\
    \    return (l==0?sum[r-1]:(sum[r-1] - sum[l-1]));\n  }\n};\n#line 6 \"2Dquery/fractional_cascading_query.cpp\"\
    \n\ntemplate<typename Val, typename Idx, typename Container,\n  Val (*id)(),\n\
    \  Val (*merge)(Val, Val),\n  Val (*query1d)(Container&, int, int),\n  Container\
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
    \ - y.begin();\n    return query(root, lx, rx, ly_idx, ry_idx);\n  }\n};\n#line\
    \ 8 \"verify/2Dquery/fractional_cascading_query.test.cpp\"\n\n#define PROBLEM\
    \ \"https://old.yosupo.jp/problem/rectangle_sum\"\n\nusing _val = long long;\n\
    using _idx = int;\nusing _container = accumulate1D<_val>;\n_val _id(){return 0;}\n\
    _val _merge(_val a, _val b){return a + b;}\n_val _query1d(_container &a, int b,\
    \ int c){return a.getsum(b, c);}\n_container _make_container(std::vector<_val>\
    \ &v){return _container(v);}\nusing rect_sum = fractional_cascading_query<_val,\
    \ _idx, _container, _id, _merge, _query1d, _make_container>;\n\n#include <iostream>\n\
    int main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n \
    \ using point = std::tuple<int, int, long long>;\n  int n, q;\n  std::cin >> n\
    \ >> q;\n  std::vector<point> p(n);\n  for(int i=0;i<n;i++){\n    int a, b, c;\n\
    \    std::cin >> a >> b >> c;\n    p[i] = std::make_tuple(a, b, c);\n  }\n  rect_sum\
    \ rect(p);\n  for(int i=0;i<q;i++){\n    int lx, ly, rx, ry;\n    std::cin >>\
    \ lx >> ly >> rx >> ry;\n    std::cout << rect.query(lx, rx, ly, ry) << '\\n';\n\
    \  }\n}\n"
  code: "#include <vector>\n#include <tuple>\n#include <algorithm>\n#include <numeric>\n\
    #include <array>\n#include \"../../1Dquery/accumulate1D.cpp\"\n#include \"../../2Dquery/fractional_cascading_query.cpp\"\
    \n\n#define PROBLEM \"https://old.yosupo.jp/problem/rectangle_sum\"\n\nusing _val\
    \ = long long;\nusing _idx = int;\nusing _container = accumulate1D<_val>;\n_val\
    \ _id(){return 0;}\n_val _merge(_val a, _val b){return a + b;}\n_val _query1d(_container\
    \ &a, int b, int c){return a.getsum(b, c);}\n_container _make_container(std::vector<_val>\
    \ &v){return _container(v);}\nusing rect_sum = fractional_cascading_query<_val,\
    \ _idx, _container, _id, _merge, _query1d, _make_container>;\n\n#include <iostream>\n\
    int main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n \
    \ using point = std::tuple<int, int, long long>;\n  int n, q;\n  std::cin >> n\
    \ >> q;\n  std::vector<point> p(n);\n  for(int i=0;i<n;i++){\n    int a, b, c;\n\
    \    std::cin >> a >> b >> c;\n    p[i] = std::make_tuple(a, b, c);\n  }\n  rect_sum\
    \ rect(p);\n  for(int i=0;i<q;i++){\n    int lx, ly, rx, ry;\n    std::cin >>\
    \ lx >> ly >> rx >> ry;\n    std::cout << rect.query(lx, rx, ly, ry) << '\\n';\n\
    \  }\n}\n"
  dependsOn:
  - 1Dquery/accumulate1D.cpp
  - 2Dquery/fractional_cascading_query.cpp
  isVerificationFile: true
  path: verify/2Dquery/fractional_cascading_query.test.cpp
  requiredBy: []
  timestamp: '2021-04-01 22:19:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/2Dquery/fractional_cascading_query.test.cpp
layout: document
redirect_from:
- /verify/verify/2Dquery/fractional_cascading_query.test.cpp
- /verify/verify/2Dquery/fractional_cascading_query.test.cpp.html
title: verify/2Dquery/fractional_cascading_query.test.cpp
---
