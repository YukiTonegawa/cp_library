#include <vector>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include "../misc/segment_merge.cpp"

template<typename Idx = int >
struct range_union_find{
private:
  segment_merge<Idx> segment;
  std::unordered_map<Idx, Idx> par, sz;

  void isolated_check(Idx u){
    if(segment.find(u).first == segment.INF){
      segment.insert(u, u+1, false);
      sz[u] = 1;
      par[u] = u;
    }
  }
  Idx _find(Idx u){
    if(par[u] == u) return u;
    return par[u] = _find(par[u]);
  }
  void _unite(Idx u, Idx v){
    u = _find(u);
    v = _find(v);
    if(u == v) return;
    if(sz[v] > sz[u]) std::swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
  }
public:
  range_union_find(){}
  void compress(Idx l, Idx r){
    isolated_check(l);
    for(auto &s:segment.enumerate_intersect(l, r)) _unite(l, s.first);
    sz[find(l)] += segment.isolated(l, r);
    segment.insert(l, r, false);
  }
  Idx find(Idx u){
    std::pair<Idx, Idx> p = segment.find(u);
    return (p.first == segment.INF ? u : _find(p.first));
  }
  Idx size(Idx u){
    std::pair<Idx, Idx> p = segment.find(u);
    return (p.first == segment.INF ? 1 : sz[_find(p.first)]);
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
    if(sz[v] > sz[u]) std::swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
  }
};
