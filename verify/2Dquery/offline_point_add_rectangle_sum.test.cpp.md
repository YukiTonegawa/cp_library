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
    \n#include <vector>\n#include <iostream>\n#include <tuple>\n#include <array>\n\
    #include <algorithm>\n#line 3 \"1Dquery/BIT.cpp\"\n\ntemplate<typename T = long\
    \ long>\nstruct BIT{\n  int M=1;\n  std::vector<T> sum;\n  BIT(){}\n  BIT(int\
    \ N): M(N), sum(M+1, 0){}\n  BIT(const std::vector<T> &v): M(v.size()), sum(1){\n\
    \    sum.insert(sum.begin()+1, v.begin(), v.end());\n    for(int i=1;i<=v.size();i++){\n\
    \      int nxt = i + (i&(-i));\n      if(nxt<=M) sum[nxt] += sum[i];\n    }\n\
    \  }\n  void add(int k, T x){\n    for(int i=k+1;i<=M;i+=(i&(-i))) sum[i] += x;\n\
    \  }\n  T getsum(int r){\n    T ret = 0;\n    for(int k=r;k>0;k-=(k&(-k))) ret\
    \ += sum[k];\n    return ret;\n  }\n  T getsum(int l, int r){\n    return getsum(r)\
    \ - getsum(l);\n  }\n};\n#line 7 \"2Dquery/offline_point_add_rectangle_sum.cpp\"\
    \n\ntemplate<typename T = long long, typename Idx = int>\nstruct point_add_rectangle_sum{\n\
    \  int M = 1;\n  std::vector<Idx> X;\n  std::vector<std::vector<Idx>> Y;\n  std::vector<BIT<T>>\
    \ BITs;\n  using point = std::tuple<Idx, Idx, T>;\n\n  point_add_rectangle_sum(){}\n\
    \  point_add_rectangle_sum(std::vector<point> v){\n    int n = v.size();\n   \
    \ sort(v.begin(), v.end(), [](const point &a, const point &b){return std::get<1>(a)\
    \ < std::get<1>(b);});\n    for(int i=0;i<n;i++) X.push_back(std::get<0>(v[i]));\n\
    \    sort(X.begin(), X.end());\n    X.erase(std::unique(X.begin(), X.end()), X.end());\n\
    \    M = (int)X.size();\n    std::vector<std::vector<T>> tmp(M+1);\n    BITs.resize(M+1);\n\
    \    Y.resize(M+1);\n    for(int i=0;i<n;i++){\n      auto [x, y, z] = v[i];\n\
    \      int k = lower_bound(X.begin(), X.end(), x) - X.begin();\n      for(int\
    \ j=k+1;j<=M;j+=(j&(-j))){\n        if(Y[j].empty()||Y[j].back()!=y){\n      \
    \    Y[j].push_back(y);\n          tmp[j].push_back(z);\n        }else{\n    \
    \      tmp[j].back() += z;\n        }\n      }\n    }\n    for(int i=0;i<=M;i++)\
    \ BITs[i] = BIT(tmp[i]);\n  }\n  void add(Idx x, Idx y, T z){\n    auto xidx =\
    \ lower_bound(X.begin(), X.end(), x) - X.begin();\n    for(int i=xidx+1;i<=M;i+=(i&(-i))){\n\
    \      auto yidx = lower_bound(Y[i].begin(), Y[i].end(), y) - Y[i].begin();\n\
    \      BITs[i].add(yidx, z);\n    }\n  }\n  T getsum(int rx, Idx ly, Idx ry){\n\
    \    T ret = 0;\n    for(int i=rx;i>0;i-=(i&(-i))){\n      int right = std::lower_bound(Y[i].begin(),\
    \ Y[i].end(), ry) - Y[i].begin();\n      int left = std::lower_bound(Y[i].begin(),\
    \ Y[i].end(), ly) - Y[i].begin();\n      ret += BITs[i].getsum(left, right);\n\
    \    }\n    return ret;\n  }\n  T getsum(Idx lx, Idx rx, Idx ly, Idx ry){\n  \
    \  T right = getsum(std::lower_bound(X.begin(), X.end(), rx)-X.begin(), ly, ry);\n\
    \    T left = getsum(std::lower_bound(X.begin(), X.end(), lx)-X.begin(), ly, ry);\n\
    \    return right - left;\n  }\n};\n#line 7 \"verify/2Dquery/offline_point_add_rectangle_sum.test.cpp\"\
    \n#define PROBLEM \"https://old.yosupo.jp/problem/point_add_rectangle_sum\"\n\n\
    int main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\n\
    \  int n, q;\n  std::cin >> n >> q;\n  std::vector<std::tuple<int, int, long long>>\
    \ v(n);\n  std::vector<std::array<long long, 5>> s(q);\n  for(int i=0;i<n;i++){\n\
    \    int a, b, c;\n    std::cin >> a >> b >> c;\n    v[i] = std::make_tuple(a,\
    \ b, c);\n  }\n  for(int i=0;i<q;i++){\n    std::cin >> s[i][0] >> s[i][1] >>\
    \ s[i][2] >> s[i][3];\n    if(s[i][0]==0) v.push_back(std::make_tuple(s[i][1],\
    \ s[i][2], 0));\n    else std::cin >> s[i][4];\n  }\n  point_add_rectangle_sum<long\
    \ long, int> rect(v);\n\n  for(int i=0;i<q;i++){\n    if(s[i][0]==0) rect.add(s[i][1],\
    \ s[i][2], s[i][3]);\n    else std::cout << rect.getsum(s[i][1], s[i][3], s[i][2],\
    \ s[i][4]) << '\\n';;\n  }\n}\n"
  code: "#include <vector>\n#include <iostream>\n#include <tuple>\n#include <array>\n\
    #include <algorithm>\n#include \"../../2Dquery/offline_point_add_rectangle_sum.cpp\"\
    \n#define PROBLEM \"https://old.yosupo.jp/problem/point_add_rectangle_sum\"\n\n\
    int main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\n\
    \  int n, q;\n  std::cin >> n >> q;\n  std::vector<std::tuple<int, int, long long>>\
    \ v(n);\n  std::vector<std::array<long long, 5>> s(q);\n  for(int i=0;i<n;i++){\n\
    \    int a, b, c;\n    std::cin >> a >> b >> c;\n    v[i] = std::make_tuple(a,\
    \ b, c);\n  }\n  for(int i=0;i<q;i++){\n    std::cin >> s[i][0] >> s[i][1] >>\
    \ s[i][2] >> s[i][3];\n    if(s[i][0]==0) v.push_back(std::make_tuple(s[i][1],\
    \ s[i][2], 0));\n    else std::cin >> s[i][4];\n  }\n  point_add_rectangle_sum<long\
    \ long, int> rect(v);\n\n  for(int i=0;i<q;i++){\n    if(s[i][0]==0) rect.add(s[i][1],\
    \ s[i][2], s[i][3]);\n    else std::cout << rect.getsum(s[i][1], s[i][3], s[i][2],\
    \ s[i][4]) << '\\n';;\n  }\n}\n"
  dependsOn:
  - 2Dquery/offline_point_add_rectangle_sum.cpp
  - 1Dquery/BIT.cpp
  isVerificationFile: true
  path: verify/2Dquery/offline_point_add_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2021-03-29 03:12:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/2Dquery/offline_point_add_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/2Dquery/offline_point_add_rectangle_sum.test.cpp
- /verify/verify/2Dquery/offline_point_add_rectangle_sum.test.cpp.html
title: verify/2Dquery/offline_point_add_rectangle_sum.test.cpp
---
