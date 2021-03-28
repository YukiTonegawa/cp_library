#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <array>
#include "../1Dquery/accumulate1D.cpp"

template<typename T, typename Idx = int>
struct fractional_cascading_query{
  using point = std::tuple<Idx, Idx, T>;

  using ds = accumulate1D<T>;
  T z = 0;
  const std::function<T(T, T)> f = [](T a, T b){return a + b;};
  
  std::vector<Idx> x, y;
  std::vector<point> p;
  struct node{
    std::pair<int, int> x_range;
    node *ch[2];
    std::vector<int> list;
    std::vector<std::array<int, 4>> next_idx;
    ds _ds;
    node(){ch[0] = ch[1] = nullptr;}
  };
  node *root;
  void build(node *v, int l, int r){
    std::vector<T> value_list(v->list.size());
    for(int i=0;i<v->list.size();i++) value_list[i] = std::get<2>(p[v->list[i]]);
    v->_ds = ds(value_list);
    if(r-l<2) return;
    int mid = (l+r)/2;
    Idx split_x = x[mid];
    v->ch[0] = new node();
    v->ch[1] = new node();
    v->ch[0]->x_range = std::make_pair(l, mid);
    v->ch[1]->x_range = std::make_pair(mid, r);
    int lsz = 0, rsz = 0;
    for(int p_idx:v->list){
      if(std::get<0>(p[p_idx]) < split_x){
        v->next_idx.push_back(std::array<int, 4>{lsz+1, lsz, rsz, rsz});
        v->ch[0]->list.push_back(p_idx);
        lsz++;
      }else{
        v->next_idx.push_back(std::array<int, 4>{lsz, lsz, rsz+1, rsz});
        v->ch[1]->list.push_back(p_idx);
        rsz++;
      }
    }
    build(v->ch[0], l, mid);
    build(v->ch[1], mid, r);
  }
  fractional_cascading_query(const std::vector<point> &points){
    p = points;
    root = new node();
    std::sort(p.begin(), p.end(), [](point &A, point &B){
      return std::get<1>(A) < std::get<1>(B);
    });
    for(int i=0;i<p.size();i++){
      x.push_back(std::get<0>(p[i]));
      y.push_back(std::get<1>(p[i]));
    }
    std::sort(x.begin(), x.end());
    x.erase(std::unique(x.begin(), x.end()), x.end());
    root->list.resize(p.size());
    std::iota(root->list.begin(), root->list.end(), 0);
    root->x_range = std::make_pair(0, x.size());
    build(root, 0, x.size());
  }
  T query(node *v, Idx lx, Idx rx, int ly, int ry){
    Idx a = x[v->x_range.first], b = x[v->x_range.second-1];
    if(!v || rx <= a || b < lx || lx >= rx || ly >= ry) return z;
    if(lx <= a && b < rx) return v->_ds.query(ly, ry);
    return f(query(v->ch[0], lx, rx, v->next_idx[ly][1], v->next_idx[ry-1][0]),
             query(v->ch[1], lx, rx, v->next_idx[ly][3], v->next_idx[ry-1][2]));
  }
  T query(Idx lx, Idx rx, Idx ly, Idx ry){
    int ly_idx = std::lower_bound(y.begin(), y.end(), ly) - y.begin();
    int ry_idx = std::lower_bound(y.begin(), y.end(), ry) - y.begin();
    return query(root, lx, rx, ly_idx, ry_idx);
  }
};
