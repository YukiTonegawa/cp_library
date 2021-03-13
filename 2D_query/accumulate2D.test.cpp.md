---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc106/tasks/abc106_d
    links:
    - https://atcoder.jp/contests/abc106/tasks/abc106_d
  bundledCode: "#line 1 \"2D_query/accumulate2D.test.cpp\"\n#include <vector>\n#include\
    \ <iostream>\n#include <functional>\n#include <cassert>\n#define PROBLEM \"https://atcoder.jp/contests/abc106/tasks/abc106_d\"\
    \nusing namespace std;\n\ntemplate<typename T>\nstruct accumulate2D{\n  vector<vector<T>>\
    \ sum;\n  function<T(T, T)> add = [](T a, T b){return a + b;};\n  function<T(T,\
    \ T)> sub = [](T a, T b){return a - b;};\n\n  accumulate2D(const vector<vector<T>>\
    \ &v){\n    assert(v.size() > 0);\n    assert(v[0].size() > 0);\n    int n = v.size(),\
    \ m = v[0].size();\n    sum.resize(n, vector<T>(m));\n    for(int j=0;j<m;j++){\n\
    \      for(int i=0;i<n;i++){\n        sum[i][j] = add((i==0?0:sum[i-1][j]), v[i][j]);\n\
    \      }\n    }\n    for(int i=0;i<n;i++){\n      for(int j=0;j<m;j++){\n    \
    \    sum[i][j] = add(sum[i][j], (j==0?0:sum[i][j-1]));\n      }\n    }\n  }\n\
    \  \n  T getsum(int lx, int rx, int ly, int ry){\n    T upper_left = (lx==0||ly==0?0:sum[lx-1][ly-1]);\n\
    \    T lower_left = (rx==0||ly==0?0:sum[rx-1][ly-1]);\n    T upper_right = (lx==0||ry==0?0:sum[lx-1][ry-1]);\n\
    \    T lower_right = (rx==0||ry==0?0:sum[rx-1][ry-1]);\n    return sub(add(upper_left,\
    \ lower_right), add(lower_left, upper_right));\n  }\n};\n\nint main(){\n  int\
    \ n, m, q;\n  std::cin >> n >> m >> q;\n  vector<vector<int>> v(n, vector<int>(n,\
    \ 0));\n  for(int i=0;i<m;i++){\n    int l, r;\n    std::cin >> l >> r;\n    v[l-1][r-1]++;\n\
    \  }\n  accumulate2D ac(v);\n  for(int i=0;i<q;i++){\n    int l, r;\n    std::cin\
    \ >> l >> r;\n    std::cout << ac.getsum(l-1, n, 0, r) << '\\n';\n  }\n}\n"
  code: "#include <vector>\n#include <iostream>\n#include <functional>\n#include <cassert>\n\
    #define PROBLEM \"https://atcoder.jp/contests/abc106/tasks/abc106_d\"\nusing namespace\
    \ std;\n\ntemplate<typename T>\nstruct accumulate2D{\n  vector<vector<T>> sum;\n\
    \  function<T(T, T)> add = [](T a, T b){return a + b;};\n  function<T(T, T)> sub\
    \ = [](T a, T b){return a - b;};\n\n  accumulate2D(const vector<vector<T>> &v){\n\
    \    assert(v.size() > 0);\n    assert(v[0].size() > 0);\n    int n = v.size(),\
    \ m = v[0].size();\n    sum.resize(n, vector<T>(m));\n    for(int j=0;j<m;j++){\n\
    \      for(int i=0;i<n;i++){\n        sum[i][j] = add((i==0?0:sum[i-1][j]), v[i][j]);\n\
    \      }\n    }\n    for(int i=0;i<n;i++){\n      for(int j=0;j<m;j++){\n    \
    \    sum[i][j] = add(sum[i][j], (j==0?0:sum[i][j-1]));\n      }\n    }\n  }\n\
    \  \n  T getsum(int lx, int rx, int ly, int ry){\n    T upper_left = (lx==0||ly==0?0:sum[lx-1][ly-1]);\n\
    \    T lower_left = (rx==0||ly==0?0:sum[rx-1][ly-1]);\n    T upper_right = (lx==0||ry==0?0:sum[lx-1][ry-1]);\n\
    \    T lower_right = (rx==0||ry==0?0:sum[rx-1][ry-1]);\n    return sub(add(upper_left,\
    \ lower_right), add(lower_left, upper_right));\n  }\n};\n\nint main(){\n  int\
    \ n, m, q;\n  std::cin >> n >> m >> q;\n  vector<vector<int>> v(n, vector<int>(n,\
    \ 0));\n  for(int i=0;i<m;i++){\n    int l, r;\n    std::cin >> l >> r;\n    v[l-1][r-1]++;\n\
    \  }\n  accumulate2D ac(v);\n  for(int i=0;i<q;i++){\n    int l, r;\n    std::cin\
    \ >> l >> r;\n    std::cout << ac.getsum(l-1, n, 0, r) << '\\n';\n  }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: 2D_query/accumulate2D.test.cpp
  requiredBy: []
  timestamp: '2021-03-13 17:56:13+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: 2D_query/accumulate2D.test.cpp
layout: document
redirect_from:
- /verify/2D_query/accumulate2D.test.cpp
- /verify/2D_query/accumulate2D.test.cpp.html
title: 2D_query/accumulate2D.test.cpp
---
