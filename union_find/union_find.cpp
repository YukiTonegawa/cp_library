#include <vector>
#include <iostream>
#include <numeric>

struct union_find{
  std::vector<int> par, sz;
  union_find(int n):par(n), sz(n, 1){
    std::iota(par.begin(), par.end(), 0);
  }
  int find(int u){
    if(par[u] == u) return u;
    return par[u] = find(par[u]);
  }
  int size(int u){
    return sz[find(u)];
  }
  bool same(int u, int v){
    return find(u) == find(v);
  }
  void unite(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return;
    if(sz[v] > sz[u]) std::swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
  }
};
