#include <vector>
#include <tuple>
#include <numeric>
#include <cassert>
#include <queue>

struct union_find_rollback{
  std::vector<int> par, sz;
  std::vector<std::tuple<bool, int, int>> history;
  std::vector<std::vector<int>> ch;
  int component;

  union_find_rollback(int n):par(n), sz(n, 1), ch(n), component(n){
    std::iota(par.begin(), par.end(), 0);
  }
  int find(int u){
    if(par[u] == u) return u;
    return find(par[u]);
  }
  int size(int u){
    return sz[find(u)];
  }
  bool same(int u, int v){
    return find(u) == find(v);
  }
  bool unite(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v){
      history.push_back({false, u, u});
      return false;
    }
    if(sz[v] > sz[u]) std::swap(u, v);
    component--;
    sz[u] += sz[v];
    ch[u].push_back(v);
    par[v] = u;
    history.push_back({true, v, u});
    return true;
  }
  std::tuple<bool, int, int> undo(){
    assert(history.size() > 0);
    auto [q, c, p] = history.back();
    history.pop_back();
    if(q==false) return {q, c, p};
    component++;
    par[c] = c;
    sz[p] -= sz[c];
    ch[p].pop_back();
    return {q, c, p};
  }
  std::vector<int> enumerate(int u){
    std::vector<int> ret;
    std::queue<int> q;
    q.push(find(u));
    while(!q.empty()){
      int v = q.front();
      q.pop();
      ret.push_back(v);
      for(int c:ch[v]) q.push(c);
    }
    return ret;
  }
  int count_connected_component(){
    return component;
  }
};
