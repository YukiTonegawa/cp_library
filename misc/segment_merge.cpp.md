---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: union_find/range_union_find.cpp
    title: union_find/range_union_find.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/segment_merge.cpp\"\n#include <vector>\n#include <numeric>\n\
    #include <map>\n\ntemplate<typename Idx = int >\nstruct segment_merge{\n  const\
    \ Idx INF = std::numeric_limits<Idx>::max();\n  std::map<Idx, Idx> mp;\n  typename\
    \ std::map<Idx, Idx>::iterator begin(){return mp.begin();}\n  typename std::map<Idx,\
    \ Idx>::iterator end(){return mp.end();}\n  segment_merge(){}\n  void insert(Idx\
    \ l, Idx r, bool merge=true){\n    auto itr = mp.upper_bound(l);\n    if(itr!=mp.begin())\
    \ itr--;\n    if(itr!=mp.end()&&(merge?itr->second<l:itr->second<=l)) itr++;\n\
    \    while(itr!=mp.end()&&(merge?itr->first<=r:itr->first<r)){\n      r = std::max(r,\
    \ itr->second);\n      l = std::min(l, itr->first);\n      itr = mp.erase(itr);\n\
    \    }\n    mp.emplace(l, r);\n  }\n  std::vector<std::pair<Idx, Idx>> enumerate_include(Idx\
    \ l, Idx r){\n    auto itr = mp.lower_bound(l);\n    std::vector<std::pair<Idx,\
    \ Idx>> ret;\n    while(itr!=mp.end()&&itr->second<=r) ret.push_back(*itr++);\n\
    \    return ret;\n  }\n  std::vector<std::pair<Idx, Idx>> enumerate_intersect(Idx\
    \ l, Idx r){\n    auto itr = mp.upper_bound(l);\n    std::vector<std::pair<Idx,\
    \ Idx>> ret;\n    while(itr!=mp.begin()&&(itr==mp.end()||itr->second>l)) itr--;\n\
    \    if(itr!=mp.end()&&itr->second<=l) itr++;\n    while(itr!=mp.end()&&itr->first<r)\
    \ ret.push_back(*itr++);\n    return ret;\n  }\n  void erase_include(Idx l, Idx\
    \ r){\n    auto itr = mp.lower_bound(l);\n    while(itr!=mp.end()&&itr->second<=r)\
    \ itr = mp.erase(itr);\n  }\n  void erase_intersect(Idx l, Idx r){\n    auto itr\
    \ = mp.upper_bound(l);\n    while(itr!=mp.begin()&&(itr==mp.end()||itr->second>l))\
    \ itr--;\n    if(itr!=mp.end()&&itr->second<=l) itr++;\n    while(itr!=mp.end()&&itr->first<r)\
    \ itr = mp.erase(itr);\n  }\n  Idx isolated(Idx l, Idx r){\n    Idx ret = Idx(0);\n\
    \    Idx itr = l;\n    for(auto &s:enumerate_intersect(l, r)){\n      if(itr <\
    \ s.first) ret += s.first - itr;\n      itr = s.second;\n    }\n    return ret\
    \ + r - std::min(itr, r);\n  }\n  Idx mex(){\n    if(mp.empty() || mp.begin()->first!=0)\
    \ return Idx(0);\n    assert((mp.size()==1||++mp.begin()->first>mp.begin()->second));\n\
    \    return I(mp.begin()->second);\n  }\n  std::pair<Idx, Idx> find(Idx p){\n\
    \    auto itr = mp.upper_bound(p);\n    if(itr!=mp.begin() && (--itr)->second\
    \ > p) return *itr;\n    else return {INF, INF};\n  }\n  bool same(Idx p, Idx\
    \ q){\n    std::pair<Idx, Idx> l = find(p), r = find(q);\n    return l.first!=INF\
    \ && l.first==r.first;\n  }\n};\n"
  code: "#include <vector>\n#include <numeric>\n#include <map>\n\ntemplate<typename\
    \ Idx = int >\nstruct segment_merge{\n  const Idx INF = std::numeric_limits<Idx>::max();\n\
    \  std::map<Idx, Idx> mp;\n  typename std::map<Idx, Idx>::iterator begin(){return\
    \ mp.begin();}\n  typename std::map<Idx, Idx>::iterator end(){return mp.end();}\n\
    \  segment_merge(){}\n  void insert(Idx l, Idx r, bool merge=true){\n    auto\
    \ itr = mp.upper_bound(l);\n    if(itr!=mp.begin()) itr--;\n    if(itr!=mp.end()&&(merge?itr->second<l:itr->second<=l))\
    \ itr++;\n    while(itr!=mp.end()&&(merge?itr->first<=r:itr->first<r)){\n    \
    \  r = std::max(r, itr->second);\n      l = std::min(l, itr->first);\n      itr\
    \ = mp.erase(itr);\n    }\n    mp.emplace(l, r);\n  }\n  std::vector<std::pair<Idx,\
    \ Idx>> enumerate_include(Idx l, Idx r){\n    auto itr = mp.lower_bound(l);\n\
    \    std::vector<std::pair<Idx, Idx>> ret;\n    while(itr!=mp.end()&&itr->second<=r)\
    \ ret.push_back(*itr++);\n    return ret;\n  }\n  std::vector<std::pair<Idx, Idx>>\
    \ enumerate_intersect(Idx l, Idx r){\n    auto itr = mp.upper_bound(l);\n    std::vector<std::pair<Idx,\
    \ Idx>> ret;\n    while(itr!=mp.begin()&&(itr==mp.end()||itr->second>l)) itr--;\n\
    \    if(itr!=mp.end()&&itr->second<=l) itr++;\n    while(itr!=mp.end()&&itr->first<r)\
    \ ret.push_back(*itr++);\n    return ret;\n  }\n  void erase_include(Idx l, Idx\
    \ r){\n    auto itr = mp.lower_bound(l);\n    while(itr!=mp.end()&&itr->second<=r)\
    \ itr = mp.erase(itr);\n  }\n  void erase_intersect(Idx l, Idx r){\n    auto itr\
    \ = mp.upper_bound(l);\n    while(itr!=mp.begin()&&(itr==mp.end()||itr->second>l))\
    \ itr--;\n    if(itr!=mp.end()&&itr->second<=l) itr++;\n    while(itr!=mp.end()&&itr->first<r)\
    \ itr = mp.erase(itr);\n  }\n  Idx isolated(Idx l, Idx r){\n    Idx ret = Idx(0);\n\
    \    Idx itr = l;\n    for(auto &s:enumerate_intersect(l, r)){\n      if(itr <\
    \ s.first) ret += s.first - itr;\n      itr = s.second;\n    }\n    return ret\
    \ + r - std::min(itr, r);\n  }\n  Idx mex(){\n    if(mp.empty() || mp.begin()->first!=0)\
    \ return Idx(0);\n    assert((mp.size()==1||++mp.begin()->first>mp.begin()->second));\n\
    \    return I(mp.begin()->second);\n  }\n  std::pair<Idx, Idx> find(Idx p){\n\
    \    auto itr = mp.upper_bound(p);\n    if(itr!=mp.begin() && (--itr)->second\
    \ > p) return *itr;\n    else return {INF, INF};\n  }\n  bool same(Idx p, Idx\
    \ q){\n    std::pair<Idx, Idx> l = find(p), r = find(q);\n    return l.first!=INF\
    \ && l.first==r.first;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/segment_merge.cpp
  requiredBy:
  - union_find/range_union_find.cpp
  timestamp: '2021-03-23 22:06:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/segment_merge.cpp
layout: document
redirect_from:
- /library/misc/segment_merge.cpp
- /library/misc/segment_merge.cpp.html
title: misc/segment_merge.cpp
---
