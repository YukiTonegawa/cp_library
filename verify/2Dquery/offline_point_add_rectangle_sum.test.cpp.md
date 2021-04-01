---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: 1Dquery/BIT.cpp
    title: 1Dquery/BIT.cpp
  - icon: ':heavy_check_mark:'
    path: 2Dquery/offline_point_add_rectangle_sum.cpp
    title: 2Dquery/offline_point_add_rectangle_sum.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://old.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://old.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"verify/2Dquery/offline_point_add_rectangle_sum.test.cpp\"\
    \n#include <iostream>\n#line 1 \"2Dquery/offline_point_add_rectangle_sum.cpp\"\
    \n#include <vector>\n#include <tuple>\n#include <array>\n#include <algorithm>\n\
    #line 3 \"1Dquery/BIT.cpp\"\n\ntemplate<typename T = long long>\nstruct BIT{\n\
    \  int M=1;\n  std::vector<T> sum;\n  BIT(){}\n  BIT(int N): M(N), sum(M+1, 0){}\n\
    \  BIT(const std::vector<T> &v): M(v.size()), sum(1){\n    sum.insert(sum.begin()+1,\
    \ v.begin(), v.end());\n    for(int i=1;i<=v.size();i++){\n      int nxt = i +\
    \ (i&(-i));\n      if(nxt<=M) sum[nxt] += sum[i];\n    }\n  }\n  void add(int\
    \ k, T x){\n    for(int i=k+1;i<=M;i+=(i&(-i))) sum[i] += x;\n  }\n  T getsum(int\
    \ r){\n    T ret = 0;\n    for(int k=r;k>0;k-=(k&(-k))) ret += sum[k];\n    return\
    \ ret;\n  }\n  T getsum(int l, int r){\n    return getsum(r) - getsum(l);\n  }\n\
    };\n#line 6 \"2Dquery/offline_point_add_rectangle_sum.cpp\"\n\ntemplate<typename\
    \ Val = long long, typename Idx = int>\nstruct point_add_rectangle_sum{\nprivate:\n\
    \  using query = std::tuple<int, Idx, Idx, Idx, Idx, Val>;//index, x, ly, ry,\
    \ value\n  using query2 = std::tuple<Idx, int, int, int, int, Val>;//x, query_type,\
    \ index, ly, ry, value\n  std::vector<query> q;\n  std::vector<int> question{0};\n\
    \  int qs = 0;\n  void solve(int l, int r, std::vector<Val> &ans){\n    if(r -\
    \ l < 2) return;\n    int mid = (l + r) >> 1;\n    solve(l, mid, ans);\n    solve(mid,\
    \ r, ans);\n    int left_insert = (mid - l) - (question[mid] - question[l]);\n\
    \    int right_question = question[r] - question[mid];\n    if(left_insert ==\
    \ 0 || right_question == 0) return;\n    std::vector<Idx> y;\n    for(int i=l;i<mid;i++)\
    \ if(std::get<0>(q[i]) == -1) y.push_back(std::get<3>(q[i]));\n    std::sort(y.begin(),\
    \ y.end());\n    y.erase(std::unique(y.begin(), y.end()), y.end());\n    BIT<Val>\
    \ bit(y.size());\n    std::vector<query2> tmp_q;\n    for(int i=l;i<mid;i++){\n\
    \      if(std::get<0>(q[i]) == -1){\n        auto [idx, lx, rx, ly, ry, val] =\
    \ q[i];\n        int y_idx = lower_bound(y.begin(), y.end(), ly) - y.begin();\n\
    \        tmp_q.push_back(std::make_tuple(lx, 2, -1, y_idx, 0, val));\n      }\n\
    \    }\n    for(int i=mid;i<r;i++){\n      if(std::get<0>(q[i]) != -1){\n    \
    \    auto [idx, lx, rx, ly, ry, val] = q[i];\n        int ly_idx = lower_bound(y.begin(),\
    \ y.end(), ly) - y.begin();\n        int ry_idx = lower_bound(y.begin(), y.end(),\
    \ ry) - y.begin();\n        tmp_q.push_back(std::make_tuple(lx, 0, idx, ly_idx,\
    \ ry_idx, 0));\n        tmp_q.push_back(std::make_tuple(rx, 1, idx, ly_idx, ry_idx,\
    \ 0));\n      }\n    }\n    std::sort(tmp_q.begin(), tmp_q.end());\n    for(auto\
    \ [x, query_type, idx, ly, ry, val]:tmp_q){\n      if(query_type == 0){\n    \
    \    ans[idx] -= bit.getsum(ly, ry);\n      }else if(query_type == 1){\n     \
    \   ans[idx] += bit.getsum(ly, ry);\n      }else{\n        bit.add(ly, val);\n\
    \      }\n    }\n  }\npublic:\n  point_add_rectangle_sum(){}\n  void add_point(Idx\
    \ x, Idx y, Val z){\n    q.push_back(std::make_tuple(-1, x, 0, y, 0, z));\n  \
    \  question.push_back(0);\n  }\n  void add_query(Idx lx, Idx rx, Idx ly, Idx ry){\n\
    \    q.push_back(std::make_tuple(qs++, lx, rx, ly, ry, 0));\n    question.push_back(1);\n\
    \  }\n  std::vector<Val> solve(){\n    std::vector<Val> ret(qs, 0);\n    for(int\
    \ i=1;i<question.size();i++) question[i] += question[i-1];\n    solve(0, q.size(),\
    \ ret);\n    return ret;\n  }\n};\n#line 3 \"verify/2Dquery/offline_point_add_rectangle_sum.test.cpp\"\
    \n#define PROBLEM \"https://old.yosupo.jp/problem/point_add_rectangle_sum\"\n\n\
    int main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n \
    \ int n, q;\n  std::cin >> n >> q;\n  point_add_rectangle_sum<long long, int>\
    \ rect;\n  for(int i=0;i<n;i++){\n    int a, b, c;\n    std::cin >> a >> b >>\
    \ c;\n    rect.add_point(a, b, c);\n  }\n  for(int i=0;i<q;i++){\n    int a, b,\
    \ c, d, e;\n    std::cin >> a >> b >> c >> d;\n    if(a==0) rect.add_point(b,\
    \ c, d);\n    else{\n      std::cin >> e;\n      rect.add_query(b, d, c, e);\n\
    \    }\n  }\n  auto ans = rect.solve();\n  for(int i=0;i<ans.size();i++) std::cout\
    \ << ans[i] << '\\n';\n}\n"
  code: "#include <iostream>\n#include \"../../2Dquery/offline_point_add_rectangle_sum.cpp\"\
    \n#define PROBLEM \"https://old.yosupo.jp/problem/point_add_rectangle_sum\"\n\n\
    int main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n \
    \ int n, q;\n  std::cin >> n >> q;\n  point_add_rectangle_sum<long long, int>\
    \ rect;\n  for(int i=0;i<n;i++){\n    int a, b, c;\n    std::cin >> a >> b >>\
    \ c;\n    rect.add_point(a, b, c);\n  }\n  for(int i=0;i<q;i++){\n    int a, b,\
    \ c, d, e;\n    std::cin >> a >> b >> c >> d;\n    if(a==0) rect.add_point(b,\
    \ c, d);\n    else{\n      std::cin >> e;\n      rect.add_query(b, d, c, e);\n\
    \    }\n  }\n  auto ans = rect.solve();\n  for(int i=0;i<ans.size();i++) std::cout\
    \ << ans[i] << '\\n';\n}\n"
  dependsOn:
  - 2Dquery/offline_point_add_rectangle_sum.cpp
  - 1Dquery/BIT.cpp
  isVerificationFile: true
  path: verify/2Dquery/offline_point_add_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2021-04-01 22:47:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/2Dquery/offline_point_add_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/2Dquery/offline_point_add_rectangle_sum.test.cpp
- /verify/verify/2Dquery/offline_point_add_rectangle_sum.test.cpp.html
title: verify/2Dquery/offline_point_add_rectangle_sum.test.cpp
---
