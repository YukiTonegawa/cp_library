#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <array>

template<typename Val, typename Idx, typename Container,
  Val (*id)(),
  Val (*merge)(Val, Val),
  Val (*query1d)(Container&, int, int),
  Container (*make_container)(std::vector<Val>&)
>
struct fractional_cascading_query{
  using point = std::tuple<Idx, Idx, Val>;
  std::vector<Idx> x, y;
  std::vector<point> p;
  struct node{
    std::pair<int, int> x_range;
    node *ch[2];
    std::vector<std::array<int, 5>> info;
    Container _ds;
    node(){ch[0] = ch[1] = nullptr;}
  };
  node *root;
  void build(node *v, int l, int r){
    std::vector<Val> value_list(v->list.size());
    for(int i=0;i<v->list.size();i++) value_list[i] = std::get<2>(p[v->list[i]]);
    v->_ds = make_container(value_list);
    if(r-l<2) return;
    int mid = (l+r)/2;
    Idx split_x = x[mid];
    v->ch[0] = new node();
    v->ch[1] = new node();
    v->ch[0]->x_range = std::make_pair(l, mid);
    v->ch[1]->x_range = std::make_pair(mid, r);
    int lsz = 0, rsz = 0;
    for(int i=0;i<v->info.size();i++){
      int p_idx = v->info[i][4];
      if(std::get<0>(p[p_idx]) < split_x){
        v->info[i][0] = lsz + 1;
        v->info[i][1] = lsz;
        v->info[i][2] = v->info[i][3] = rsz;
        v->ch[0]->info.push_back({-1, -1, -1, -1, p_idx});
        lsz++;
      }else{
        v->info[i][0] = v->info[i][1] = lsz;
        v->info[i][2] = rsz + 1;
        v->info[i][3] = rsz;
        v->ch[1]->info.push_back({-1, -1, -1, -1, p_idx});
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
    root->info.resize(p.size());
    for(int i=0;i<p.size();i++) root->info[i] = {-1, -1, -1, -1, i};
    root->x_range = std::make_pair(0, x.size());
    build(root, 0, x.size());
  }
  Val query(node *v, Idx lx, Idx rx, int ly, int ry){
    Idx a = x[v->x_range.first], b = x[v->x_range.second-1];
    if(!v || rx <= a || b < lx || lx >= rx || ly >= ry) return id();
    if(lx <= a && b < rx) return query1d(v->_ds, ly, ry);
    return merge(query(v->ch[0], lx, rx, v->next_idx[ly][1], v->next_idx[ry-1][0]),
             query(v->ch[1], lx, rx, v->next_idx[ly][3], v->next_idx[ry-1][2]));
  }
  Val query(Idx lx, Idx rx, Idx ly, Idx ry){
    int ly_idx = std::lower_bound(y.begin(), y.end(), ly) - y.begin();
    int ry_idx = std::lower_bound(y.begin(), y.end(), ry) - y.begin();
    return query(root, lx, rx, ly_idx, ry_idx);
  }
};
