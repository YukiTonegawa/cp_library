#include <vector>
#include <numeric>
#include <map>

template<typename Idx = int >
struct segment_merge{
  const Idx INF = std::numeric_limits<Idx>::max();
  std::map<Idx, Idx> mp;
  typename std::map<Idx, Idx>::iterator begin(){return mp.begin();}
  typename std::map<Idx, Idx>::iterator end(){return mp.end();}
  segment_merge(){}
  void insert(Idx l, Idx r, bool merge=true){
    auto itr = mp.upper_bound(l);
    if(itr!=mp.begin()) itr--;
    if(itr!=mp.end()&&(merge?itr->second<l:itr->second<=l)) itr++;
    while(itr!=mp.end()&&(merge?itr->first<=r:itr->first<r)){
      r = std::max(r, itr->second);
      l = std::min(l, itr->first);
      itr = mp.erase(itr);
    }
    mp.emplace(l, r);
  }
  std::vector<std::pair<Idx, Idx>> enumerate_include(Idx l, Idx r){
    auto itr = mp.lower_bound(l);
    std::vector<std::pair<Idx, Idx>> ret;
    while(itr!=mp.end()&&itr->second<=r) ret.push_back(*itr++);
    return ret;
  }
  std::vector<std::pair<Idx, Idx>> enumerate_intersect(Idx l, Idx r){
    auto itr = mp.upper_bound(l);
    std::vector<std::pair<Idx, Idx>> ret;
    while(itr!=mp.begin()&&(itr==mp.end()||itr->second>l)) itr--;
    if(itr!=mp.end()&&itr->second<=l) itr++;
    while(itr!=mp.end()&&itr->first<r) ret.push_back(*itr++);
    return ret;
  }
  void erase_include(Idx l, Idx r){
    auto itr = mp.lower_bound(l);
    while(itr!=mp.end()&&itr->second<=r) itr = mp.erase(itr);
  }
  void erase_intersect(Idx l, Idx r){
    auto itr = mp.upper_bound(l);
    while(itr!=mp.begin()&&(itr==mp.end()||itr->second>l)) itr--;
    if(itr!=mp.end()&&itr->second<=l) itr++;
    while(itr!=mp.end()&&itr->first<r) itr = mp.erase(itr);
  }
  Idx isolated(Idx l, Idx r){
    Idx ret = Idx(0);
    Idx itr = l;
    for(auto &s:enumerate_intersect(l, r)){
      if(itr < s.first) ret += s.first - itr;
      itr = s.second;
    }
    return ret + r - std::min(itr, r);
  }
  Idx mex(){
    if(mp.empty() || mp.begin()->first!=0) return Idx(0);
    assert((mp.size()==1||++mp.begin()->first>mp.begin()->second));
    return I(mp.begin()->second);
  }
  std::pair<Idx, Idx> find(Idx p){
    auto itr = mp.upper_bound(p);
    if(itr!=mp.begin() && (--itr)->second > p) return *itr;
    else return {INF, INF};
  }
  bool same(Idx p, Idx q){
    std::pair<Idx, Idx> l = find(p), r = find(q);
    return l.first!=INF && l.first==r.first;
  }
};
