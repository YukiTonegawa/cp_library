---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: misc/segment_merge.cpp
    title: misc/segment_merge.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"union_find/range_union_find.cpp\"\n#include <vector>\n#include\
    \ <iostream>\n#include <numeric>\n#include <unordered_map>\n#include <array>\n\
    #line 3 \"misc/segment_merge.cpp\"\n#include <map>\n\ntemplate<typename Idx =\
    \ int >\nstruct segment_merge{\n  const Idx INF = std::numeric_limits<Idx>::max();\n\
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
    \ && l.first==r.first;\n  }\n};\n#line 7 \"union_find/range_union_find.cpp\"\n\
    \ntemplate<typename Idx = int >\nstruct range_union_find{\nprivate:\n  segment_merge<Idx>\
    \ segment;\n  std::unordered_map<Idx, std::array<Idx, 3>> info;\n  void isolated_check(Idx\
    \ u){\n    if(segment.find(u).first == segment.INF){\n      segment.insert(u,\
    \ u+1, false);\n      info.emplace(u, std::array<Idx, 3>{1, 1, u});\n    }\n \
    \ }\n  Idx _find(Idx u){\n    std::array<Idx, 3> &ui = info.at(u);\n    if(ui[2]\
    \ == u) return u;\n    return ui[2] = _find(ui[2]);\n  }\n  void _unite(Idx u,\
    \ Idx v){\n    u = _find(u);\n    v = _find(v);\n    if(u == v) return;\n    std::array<Idx,\
    \ 3> &ui = info.at(u), &vi = info.at(v);\n    if(vi[1] > ui[1]) vi[0] += ui[0],\
    \ vi[1]++, ui[2] = v;\n    else ui[0] += vi[0], ui[1]++, vi[2] = u;\n  }\npublic:\n\
    \  range_union_find(){}\n  void compress(Idx l, Idx r){\n    isolated_check(l);\n\
    \    Idx lp = find(l);\n    for(auto &s:segment.enumerate_intersect(l, r)) _unite(lp,\
    \ s.first);\n    lp = _find(lp);\n    std::array<Idx, 3> &li = info.at(lp);\n\
    \    li[0] += segment.isolated(l, r);\n    segment.insert(l, r, false);\n  }\n\
    \  Idx find(Idx u){\n    Idx v = segment.find(u).first;\n    if(v == segment.INF)\
    \ return Idx(u);\n    return _find(v);\n  }\n  Idx size(Idx u){\n    Idx v = segment.find(u).first;\n\
    \    if(v == segment.INF) return Idx(1);\n    std::array<Idx, 3> &vi = info.at(_find(v));\n\
    \    return vi[0];\n  }\n  bool same(Idx u, Idx v){\n    return find(u) == find(v);\n\
    \  }\n  void unite(Idx u, Idx v){\n    isolated_check(u);\n    isolated_check(v);\n\
    \    u = find(u);\n    v = find(v);\n    if(u == v) return;\n    std::array<Idx,\
    \ 3> &ui = info.at(u), &vi = info.at(v);\n    if(vi[1] > ui[1]) vi[0] += ui[0],\
    \ vi[1]++, ui[2] = v;\n    else ui[0] += vi[0], ui[1]++, vi[2] = u;\n  }\n};\n"
  code: "#include <vector>\n#include <iostream>\n#include <numeric>\n#include <unordered_map>\n\
    #include <array>\n#include \"../misc/segment_merge.cpp\"\n\ntemplate<typename\
    \ Idx = int >\nstruct range_union_find{\nprivate:\n  segment_merge<Idx> segment;\n\
    \  std::unordered_map<Idx, std::array<Idx, 3>> info;\n  void isolated_check(Idx\
    \ u){\n    if(segment.find(u).first == segment.INF){\n      segment.insert(u,\
    \ u+1, false);\n      info.emplace(u, std::array<Idx, 3>{1, 1, u});\n    }\n \
    \ }\n  Idx _find(Idx u){\n    std::array<Idx, 3> &ui = info.at(u);\n    if(ui[2]\
    \ == u) return u;\n    return ui[2] = _find(ui[2]);\n  }\n  void _unite(Idx u,\
    \ Idx v){\n    u = _find(u);\n    v = _find(v);\n    if(u == v) return;\n    std::array<Idx,\
    \ 3> &ui = info.at(u), &vi = info.at(v);\n    if(vi[1] > ui[1]) vi[0] += ui[0],\
    \ vi[1]++, ui[2] = v;\n    else ui[0] += vi[0], ui[1]++, vi[2] = u;\n  }\npublic:\n\
    \  range_union_find(){}\n  void compress(Idx l, Idx r){\n    isolated_check(l);\n\
    \    Idx lp = find(l);\n    for(auto &s:segment.enumerate_intersect(l, r)) _unite(lp,\
    \ s.first);\n    lp = _find(lp);\n    std::array<Idx, 3> &li = info.at(lp);\n\
    \    li[0] += segment.isolated(l, r);\n    segment.insert(l, r, false);\n  }\n\
    \  Idx find(Idx u){\n    Idx v = segment.find(u).first;\n    if(v == segment.INF)\
    \ return Idx(u);\n    return _find(v);\n  }\n  Idx size(Idx u){\n    Idx v = segment.find(u).first;\n\
    \    if(v == segment.INF) return Idx(1);\n    std::array<Idx, 3> &vi = info.at(_find(v));\n\
    \    return vi[0];\n  }\n  bool same(Idx u, Idx v){\n    return find(u) == find(v);\n\
    \  }\n  void unite(Idx u, Idx v){\n    isolated_check(u);\n    isolated_check(v);\n\
    \    u = find(u);\n    v = find(v);\n    if(u == v) return;\n    std::array<Idx,\
    \ 3> &ui = info.at(u), &vi = info.at(v);\n    if(vi[1] > ui[1]) vi[0] += ui[0],\
    \ vi[1]++, ui[2] = v;\n    else ui[0] += vi[0], ui[1]++, vi[2] = u;\n  }\n};\n"
  dependsOn:
  - misc/segment_merge.cpp
  isVerificationFile: false
  path: union_find/range_union_find.cpp
  requiredBy: []
  timestamp: '2021-03-26 13:43:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: union_find/range_union_find.cpp
layout: document
redirect_from:
- /library/union_find/range_union_find.cpp
- /library/union_find/range_union_find.cpp.html
title: union_find/range_union_find.cpp
---
