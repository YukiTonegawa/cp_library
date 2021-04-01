---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: 1Dquery/BIT.cpp
    title: 1Dquery/BIT.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/2Dquery/partial_offline_point_add_rectangle_sum.test.cpp
    title: verify/2Dquery/partial_offline_point_add_rectangle_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"2Dquery/partial_offline_point_add_rectangle_sum.cpp\"\n\
    #include <vector>\n#include <tuple>\n#include <algorithm>\n#line 2 \"1Dquery/BIT.cpp\"\
    \n#include <iostream>\n\ntemplate<typename T = long long>\nstruct BIT{\n  int\
    \ M=1;\n  std::vector<T> sum;\n  BIT(){}\n  BIT(int N): M(N), sum(M+1, 0){}\n\
    \  BIT(const std::vector<T> &v): M(v.size()), sum(1){\n    sum.insert(sum.begin()+1,\
    \ v.begin(), v.end());\n    for(int i=1;i<=v.size();i++){\n      int nxt = i +\
    \ (i&(-i));\n      if(nxt<=M) sum[nxt] += sum[i];\n    }\n  }\n  void add(int\
    \ k, T x){\n    for(int i=k+1;i<=M;i+=(i&(-i))) sum[i] += x;\n  }\n  T getsum(int\
    \ r){\n    T ret = 0;\n    for(int k=r;k>0;k-=(k&(-k))) ret += sum[k];\n    return\
    \ ret;\n  }\n  T getsum(int l, int r){\n    return getsum(r) - getsum(l);\n  }\n\
    };\n#line 5 \"2Dquery/partial_offline_point_add_rectangle_sum.cpp\"\n\ntemplate<typename\
    \ Val = long long, typename Idx = int>\nstruct point_add_rectangle_sum{\nprivate:\n\
    \  int M = 1;\n  std::vector<Idx> X;\n  std::vector<std::vector<Idx>> Y;\n  std::vector<BIT<Val>>\
    \ BITs;\n  using point = std::tuple<Idx, Idx, Val>;\npublic:\n  point_add_rectangle_sum(){}\n\
    \  point_add_rectangle_sum(std::vector<point> v){\n    int n = v.size();\n   \
    \ std::sort(v.begin(), v.end(), [](const point &a, const point &b){return std::get<1>(a)\
    \ < std::get<1>(b);});\n    for(int i=0;i<n;i++) X.push_back(std::get<0>(v[i]));\n\
    \    std::sort(X.begin(), X.end());\n    X.erase(std::unique(X.begin(), X.end()),\
    \ X.end());\n    M = (int)X.size();\n    std::vector<std::vector<Val>> tmp(M+1);\n\
    \    BITs.resize(M+1);\n    Y.resize(M+1);\n    for(int i=0;i<n;i++){\n      auto\
    \ [x, y, z] = v[i];\n      int k = lower_bound(X.begin(), X.end(), x) - X.begin();\n\
    \      for(int j=k+1;j<=M;j+=(j&(-j))){\n        if(Y[j].empty()||Y[j].back()!=y){\n\
    \          Y[j].push_back(y);\n          tmp[j].push_back(z);\n        }else{\n\
    \          tmp[j].back() += z;\n        }\n      }\n    }\n    for(int i=0;i<=M;i++)\
    \ BITs[i] = BIT(tmp[i]);\n  }\n  void add(Idx x, Idx y, Val z){\n    auto xidx\
    \ = lower_bound(X.begin(), X.end(), x) - X.begin();\n    for(int i=xidx+1;i<=M;i+=(i&(-i))){\n\
    \      auto yidx = lower_bound(Y[i].begin(), Y[i].end(), y) - Y[i].begin();\n\
    \      BITs[i].add(yidx, z);\n    }\n  }\n  Val getsum(int rx, Idx ly, Idx ry){\n\
    \    Val ret = 0;\n    for(int i=rx;i>0;i-=(i&(-i))){\n      int right = std::lower_bound(Y[i].begin(),\
    \ Y[i].end(), ry) - Y[i].begin();\n      int left = std::lower_bound(Y[i].begin(),\
    \ Y[i].end(), ly) - Y[i].begin();\n      ret += BITs[i].getsum(left, right);\n\
    \    }\n    return ret;\n  }\n  Val getsum(Idx lx, Idx rx, Idx ly, Idx ry){\n\
    \    Val right = getsum(std::lower_bound(X.begin(), X.end(), rx)-X.begin(), ly,\
    \ ry);\n    Val left = getsum(std::lower_bound(X.begin(), X.end(), lx)-X.begin(),\
    \ ly, ry);\n    return right - left;\n  }\n};\n"
  code: "#include <vector>\n#include <tuple>\n#include <algorithm>\n#include \"../1Dquery/BIT.cpp\"\
    \n\ntemplate<typename Val = long long, typename Idx = int>\nstruct point_add_rectangle_sum{\n\
    private:\n  int M = 1;\n  std::vector<Idx> X;\n  std::vector<std::vector<Idx>>\
    \ Y;\n  std::vector<BIT<Val>> BITs;\n  using point = std::tuple<Idx, Idx, Val>;\n\
    public:\n  point_add_rectangle_sum(){}\n  point_add_rectangle_sum(std::vector<point>\
    \ v){\n    int n = v.size();\n    std::sort(v.begin(), v.end(), [](const point\
    \ &a, const point &b){return std::get<1>(a) < std::get<1>(b);});\n    for(int\
    \ i=0;i<n;i++) X.push_back(std::get<0>(v[i]));\n    std::sort(X.begin(), X.end());\n\
    \    X.erase(std::unique(X.begin(), X.end()), X.end());\n    M = (int)X.size();\n\
    \    std::vector<std::vector<Val>> tmp(M+1);\n    BITs.resize(M+1);\n    Y.resize(M+1);\n\
    \    for(int i=0;i<n;i++){\n      auto [x, y, z] = v[i];\n      int k = lower_bound(X.begin(),\
    \ X.end(), x) - X.begin();\n      for(int j=k+1;j<=M;j+=(j&(-j))){\n        if(Y[j].empty()||Y[j].back()!=y){\n\
    \          Y[j].push_back(y);\n          tmp[j].push_back(z);\n        }else{\n\
    \          tmp[j].back() += z;\n        }\n      }\n    }\n    for(int i=0;i<=M;i++)\
    \ BITs[i] = BIT(tmp[i]);\n  }\n  void add(Idx x, Idx y, Val z){\n    auto xidx\
    \ = lower_bound(X.begin(), X.end(), x) - X.begin();\n    for(int i=xidx+1;i<=M;i+=(i&(-i))){\n\
    \      auto yidx = lower_bound(Y[i].begin(), Y[i].end(), y) - Y[i].begin();\n\
    \      BITs[i].add(yidx, z);\n    }\n  }\n  Val getsum(int rx, Idx ly, Idx ry){\n\
    \    Val ret = 0;\n    for(int i=rx;i>0;i-=(i&(-i))){\n      int right = std::lower_bound(Y[i].begin(),\
    \ Y[i].end(), ry) - Y[i].begin();\n      int left = std::lower_bound(Y[i].begin(),\
    \ Y[i].end(), ly) - Y[i].begin();\n      ret += BITs[i].getsum(left, right);\n\
    \    }\n    return ret;\n  }\n  Val getsum(Idx lx, Idx rx, Idx ly, Idx ry){\n\
    \    Val right = getsum(std::lower_bound(X.begin(), X.end(), rx)-X.begin(), ly,\
    \ ry);\n    Val left = getsum(std::lower_bound(X.begin(), X.end(), lx)-X.begin(),\
    \ ly, ry);\n    return right - left;\n  }\n};\n"
  dependsOn:
  - 1Dquery/BIT.cpp
  isVerificationFile: false
  path: 2Dquery/partial_offline_point_add_rectangle_sum.cpp
  requiredBy: []
  timestamp: '2021-04-01 21:41:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/2Dquery/partial_offline_point_add_rectangle_sum.test.cpp
documentation_of: 2Dquery/partial_offline_point_add_rectangle_sum.cpp
layout: document
redirect_from:
- /library/2Dquery/partial_offline_point_add_rectangle_sum.cpp
- /library/2Dquery/partial_offline_point_add_rectangle_sum.cpp.html
title: 2Dquery/partial_offline_point_add_rectangle_sum.cpp
---
