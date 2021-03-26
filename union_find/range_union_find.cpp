#include <vector>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <array>
#include "../misc/segment_merge.cpp"

template<typename Idx = int >
struct range_union_find{
private:
  segment_merge<Idx> segment;
  std::unordered_map<Idx, std::array<Idx, 3>> info;
  void isolated_check(Idx u){
    if(segment.find(u).first == segment.INF){
      segment.insert(u, u+1, false);
      info.emplace(u, std::array<Idx, 3>{1, 1, u});
    }
  }
  Idx _find(Idx u){
    std::array<Idx, 3> &ui = info.at(u);
    if(ui[2] == u) return u;
    return ui[2] = _find(ui[2]);
  }
  void _unite(Idx u, Idx v){
    u = _find(u);
    v = _find(v);
    if(u == v) return;
    std::array<Idx, 3> &ui = info.at(u), &vi = info.at(v);
    if(vi[1] > ui[1]) vi[0] += ui[0], vi[1]++, ui[2] = v;
    else ui[0] += vi[0], ui[1]++, vi[2] = u;
  }
public:
  range_union_find(){}
  void compress(Idx l, Idx r){
    isolated_check(l);
    Idx lp = find(l);
    for(auto &s:segment.enumerate_intersect(l, r)) _unite(lp, s.first);
    lp = _find(lp);
    std::array<Idx, 3> &li = info.at(lp);
    li[0] += segment.isolated(l, r);
    segment.insert(l, r, false);
  }
  Idx find(Idx u){
    Idx v = segment.find(u).first;
    if(v == segment.INF) return Idx(u);
    return _find(v);
  }
  Idx size(Idx u){
    Idx v = segment.find(u).first;
    if(v == segment.INF) return Idx(1);
    std::array<Idx, 3> &vi = info.at(_find(v));
    return vi[0];
  }
  bool same(Idx u, Idx v){
    return find(u) == find(v);
  }
  void unite(Idx u, Idx v){
    isolated_check(u);
    isolated_check(v);
    u = find(u);
    v = find(v);
    if(u == v) return;
    std::array<Idx, 3> &ui = info.at(u), &vi = info.at(v);
    if(vi[1] > ui[1]) vi[0] += ui[0], vi[1]++, ui[2] = v;
    else ui[0] += vi[0], ui[1]++, vi[2] = u;
  }
};
