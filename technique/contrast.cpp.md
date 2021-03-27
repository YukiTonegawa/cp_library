---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"technique/contrast.cpp\"\n#include <vector>\n#include <cassert>\n\
    #include <numeric>\n#include <algorithm>\n#include <unordered_map>\n\ntemplate<typename\
    \ T>\nstd::vector<int> contrast(const std::vector<T> &x, const std::vector<T>\
    \ &y, bool is_sorted = false){\n  assert(x.size() == y.size());\n  int n = x.size();\n\
    \  std::vector<int> x_idx(n), y_idx, ret(n);\n  std::iota(x_idx.begin(), x_idx.end(),\
    \ 0);\n  y_idx = x_idx;\n  if(is_sorted){\n    std::reverse(y_idx.begin(), y_idx.end());\n\
    \  }else{\n    std::sort(x_idx.begin(), x_idx.end(), [&x](int A, int B){return\
    \ x[A] < x[B];});\n    std::sort(y_idx.begin(), y_idx.end(), [&y](int A, int B){return\
    \ y[A] > y[B];});\n  }\n  T dup_element;\n  for(int i=0;i<n;i++){\n    if(x[x_idx[i]]\
    \ == y[y_idx[i]]){\n      dup_element = x[x_idx[i]];\n      break;\n    }\n  }\n\
    \  std::vector<int> safe, dup;\n  for(int i=0;i<n;i++){\n    if(x[x_idx[i]] ==\
    \ y[y_idx[i]]){\n      dup.push_back(i);\n    }\n    if(x[x_idx[i]] != dup_element\
    \ && y[y_idx[i]] != dup_element){\n      safe.push_back(i);\n    }\n  }\n  if(!dup.empty()){\n\
    \    if(dup.size() > safe.size()) return std::vector<int>();\n    while(!dup.empty()){\n\
    \      std::swap(y_idx[dup.back()], y_idx[safe.back()]);\n      dup.pop_back();\n\
    \      safe.pop_back();\n    }\n  }\n  for(int i=0;i<n;i++) ret[x_idx[i]] = y_idx[i];\n\
    \  return ret;\n}\n\ntemplate<typename T>\nstd::pair<int, std::vector<int>> contrast_maximum_matching(const\
    \ std::vector<T> &x, const std::vector<T> &y, bool is_sorted = false){\n  int\
    \ n = x.size(), m = y.size();\n  std::vector<int> ret(n, -1), x_idx, y_idx;;\n\
    \  std::unordered_map<T, int> cnt;\n  if(n < m){\n    x_idx.resize(n);\n    std::iota(x_idx.begin(),\
    \ x_idx.end(), 0);\n    for(int i=0;i<n;i++) cnt[x[i]]++;\n    for(int i=0;i<m;i++){\n\
    \      if(cnt[y[i]] < n || n - y_idx.size() == m - i){\n        y_idx.push_back(i);\n\
    \        cnt[y[i]]++;\n      }\n      if(y_idx.size() == n) break;\n    }\n  }else\
    \ if(n > m){\n    y_idx.resize(m);\n    std::iota(y_idx.begin(), y_idx.end(),\
    \ 0);\n    for(int i=0;i<m;i++) cnt[y[i]]++;\n    for(int i=0;i<n;i++){\n    \
    \  if(cnt[x[i]] < m || m - x_idx.size() == n - i){\n        x_idx.push_back(i);\n\
    \        cnt[x[i]]++;\n      }\n      if(x_idx.size() == m) break;\n    }\n  }\n\
    \  n = std::min(n, m);\n  if(is_sorted){\n    std::reverse(y_idx.begin(), y_idx.end());\n\
    \  }else{\n    std::sort(x_idx.begin(), x_idx.end(), [&x](int A, int B){return\
    \ x[A] < x[B];});\n    std::sort(y_idx.begin(), y_idx.end(), [&y](int A, int B){return\
    \ y[A] > y[B];});\n  }\n  T dup_element;\n  for(int i=0;i<n;i++){\n    if(x[x_idx[i]]\
    \ == y[y_idx[i]]){\n      dup_element = x[x_idx[i]];\n      break;\n    }\n  }\n\
    \  std::vector<int> safe, dup;\n  for(int i=0;i<n;i++){\n    if(x[x_idx[i]] ==\
    \ y[y_idx[i]]){\n      dup.push_back(i);\n    }\n    if(x[x_idx[i]] != dup_element\
    \ && y[y_idx[i]] != dup_element){\n      safe.push_back(i);\n    }\n  }\n  if(!dup.empty()){\n\
    \    while(!dup.empty() && !safe.empty()){\n      std::swap(y_idx[dup.back()],\
    \ y_idx[safe.back()]);\n      dup.pop_back();\n      safe.pop_back();\n    }\n\
    \  }\n  for(int i=0;i<n;i++) ret[x_idx[i]] = y_idx[i];\n  for(int d:dup) ret[x_idx[d]]\
    \ = -1;\n  return {n - dup.size(), ret};\n}\n"
  code: "#include <vector>\n#include <cassert>\n#include <numeric>\n#include <algorithm>\n\
    #include <unordered_map>\n\ntemplate<typename T>\nstd::vector<int> contrast(const\
    \ std::vector<T> &x, const std::vector<T> &y, bool is_sorted = false){\n  assert(x.size()\
    \ == y.size());\n  int n = x.size();\n  std::vector<int> x_idx(n), y_idx, ret(n);\n\
    \  std::iota(x_idx.begin(), x_idx.end(), 0);\n  y_idx = x_idx;\n  if(is_sorted){\n\
    \    std::reverse(y_idx.begin(), y_idx.end());\n  }else{\n    std::sort(x_idx.begin(),\
    \ x_idx.end(), [&x](int A, int B){return x[A] < x[B];});\n    std::sort(y_idx.begin(),\
    \ y_idx.end(), [&y](int A, int B){return y[A] > y[B];});\n  }\n  T dup_element;\n\
    \  for(int i=0;i<n;i++){\n    if(x[x_idx[i]] == y[y_idx[i]]){\n      dup_element\
    \ = x[x_idx[i]];\n      break;\n    }\n  }\n  std::vector<int> safe, dup;\n  for(int\
    \ i=0;i<n;i++){\n    if(x[x_idx[i]] == y[y_idx[i]]){\n      dup.push_back(i);\n\
    \    }\n    if(x[x_idx[i]] != dup_element && y[y_idx[i]] != dup_element){\n  \
    \    safe.push_back(i);\n    }\n  }\n  if(!dup.empty()){\n    if(dup.size() >\
    \ safe.size()) return std::vector<int>();\n    while(!dup.empty()){\n      std::swap(y_idx[dup.back()],\
    \ y_idx[safe.back()]);\n      dup.pop_back();\n      safe.pop_back();\n    }\n\
    \  }\n  for(int i=0;i<n;i++) ret[x_idx[i]] = y_idx[i];\n  return ret;\n}\n\ntemplate<typename\
    \ T>\nstd::pair<int, std::vector<int>> contrast_maximum_matching(const std::vector<T>\
    \ &x, const std::vector<T> &y, bool is_sorted = false){\n  int n = x.size(), m\
    \ = y.size();\n  std::vector<int> ret(n, -1), x_idx, y_idx;;\n  std::unordered_map<T,\
    \ int> cnt;\n  if(n < m){\n    x_idx.resize(n);\n    std::iota(x_idx.begin(),\
    \ x_idx.end(), 0);\n    for(int i=0;i<n;i++) cnt[x[i]]++;\n    for(int i=0;i<m;i++){\n\
    \      if(cnt[y[i]] < n || n - y_idx.size() == m - i){\n        y_idx.push_back(i);\n\
    \        cnt[y[i]]++;\n      }\n      if(y_idx.size() == n) break;\n    }\n  }else\
    \ if(n > m){\n    y_idx.resize(m);\n    std::iota(y_idx.begin(), y_idx.end(),\
    \ 0);\n    for(int i=0;i<m;i++) cnt[y[i]]++;\n    for(int i=0;i<n;i++){\n    \
    \  if(cnt[x[i]] < m || m - x_idx.size() == n - i){\n        x_idx.push_back(i);\n\
    \        cnt[x[i]]++;\n      }\n      if(x_idx.size() == m) break;\n    }\n  }\n\
    \  n = std::min(n, m);\n  if(is_sorted){\n    std::reverse(y_idx.begin(), y_idx.end());\n\
    \  }else{\n    std::sort(x_idx.begin(), x_idx.end(), [&x](int A, int B){return\
    \ x[A] < x[B];});\n    std::sort(y_idx.begin(), y_idx.end(), [&y](int A, int B){return\
    \ y[A] > y[B];});\n  }\n  T dup_element;\n  for(int i=0;i<n;i++){\n    if(x[x_idx[i]]\
    \ == y[y_idx[i]]){\n      dup_element = x[x_idx[i]];\n      break;\n    }\n  }\n\
    \  std::vector<int> safe, dup;\n  for(int i=0;i<n;i++){\n    if(x[x_idx[i]] ==\
    \ y[y_idx[i]]){\n      dup.push_back(i);\n    }\n    if(x[x_idx[i]] != dup_element\
    \ && y[y_idx[i]] != dup_element){\n      safe.push_back(i);\n    }\n  }\n  if(!dup.empty()){\n\
    \    while(!dup.empty() && !safe.empty()){\n      std::swap(y_idx[dup.back()],\
    \ y_idx[safe.back()]);\n      dup.pop_back();\n      safe.pop_back();\n    }\n\
    \  }\n  for(int i=0;i<n;i++) ret[x_idx[i]] = y_idx[i];\n  for(int d:dup) ret[x_idx[d]]\
    \ = -1;\n  return {n - dup.size(), ret};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: technique/contrast.cpp
  requiredBy: []
  timestamp: '2021-03-28 03:35:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: technique/contrast.cpp
layout: document
redirect_from:
- /library/technique/contrast.cpp
- /library/technique/contrast.cpp.html
title: technique/contrast.cpp
---
