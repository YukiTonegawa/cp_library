#include <vector>
#include <tuple>
#include <numeric>
#include <cassert>

struct union_find_rollback{
  std::vector<int> par, sz;
  std::vector<std::tuple<bool, int, int>> history;

  union_find_rollback(int n):par(n), sz(n, 1){
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
    sz[u] += sz[v];
    par[v] = u;
    history.push_back({true, v, u});
    return true;
  }
  std::tuple<bool, int, int> undo(){
    assert(history.size() > 0);
    auto [q, c, p] = history.back();
    history.pop_back();
    if(q==false) return {q, c, p};
    par[c] = c;
    sz[p] -= sz[c];
    return {q, c, p};
  }
};
