#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <array>

template<typename Val, typename Idx, typename Container,
  Val (*id)(),
  Val (*merge)(Val, Val),
  Val (*query1d)(Container&, int, int),
  void (*update1d)(Container&, int, Val),
  Container (*make_container)(std::vector<Val>&)
>
struct fractional_cascading_query{
  using input_point = std::tuple<Idx, Idx, Val>;
  using point = std::tuple<Idx, Idx, Val, int>;
  std::vector<Idx> x, y;
  std::vector<point> p;
  std::vector<int> sorted_index, rev_index;
  std::vector<std::vector<int>> kth_index;
  struct node{
    std::pair<int, int> x_range;
    node *ch[2];
    std::vector<std::array<int, 5>> info;
    Container _ds;
    node(){ch[0] = ch[1] = nullptr;}
  };
  node *root;
  void build(node *v, int l, int r, int dep = 0){
    if(kth_index.size() == dep) kth_index.push_back(std::vector<int>(p.size()));
    std::vector<Val> value_list(v->info.size());
    for(int i=0;i<v->info.size();i++) value_list[i] = std::get<2>(p[v->info[i][4]]);
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
        kth_index[dep][p_idx] = lsz;
        v->ch[0]->info.push_back({-1, -1, -1, -1, p_idx});
        lsz++;
      }else{
        v->info[i][0] = v->info[i][1] = lsz;
        v->info[i][2] = rsz + 1;
        v->info[i][3] = rsz;
        kth_index[dep][p_idx] = rsz;
        v->ch[1]->info.push_back({-1, -1, -1, -1, p_idx});
        rsz++;
      }
    }
    build(v->ch[0], l, mid, dep + 1);
    build(v->ch[1], mid, r, dep + 1);
  }
  fractional_cascading_query(const std::vector<input_point> &points){
    p.resize(points.size());
    int i = 0;
    for(auto [x, y, v] : points){
      p[i] = std::make_tuple(x, y, v, i);
      i++;
    }
    root = new node();
    std::sort(p.begin(), p.end(), [](point &A, point &B){
      return std::get<1>(A) < std::get<1>(B);
    });
    sorted_index.resize(p.size());
    rev_index.resize(p.size());
    for(int i=0;i<p.size();i++){
      x.push_back(std::get<0>(p[i]));
      y.push_back(std::get<1>(p[i]));
      sorted_index[std::get<3>(p[i])] = i;
      rev_index[i] = std::get<3>(p[i]);
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
    if(!v || rx <= a || b < lx || ly >= ry) return id();
    if(lx <= a && b < rx) return query1d(v->_ds, ly, ry);
    return merge(query(v->ch[0], lx, rx, v->info[ly][1], v->info[ry-1][0]),
             query(v->ch[1], lx, rx, v->info[ly][3], v->info[ry-1][2]));
  }
  Val query(Idx lx, Idx rx, Idx ly, Idx ry){
    if(lx >= rx || ly >= ry) return id();
    int ly_idx = std::lower_bound(y.begin(), y.end(), ly) - y.begin();
    int ry_idx = std::lower_bound(y.begin(), y.end(), ry) - y.begin();
    return query(root, lx, rx, ly_idx, ry_idx);
  }
  std::pair<int, int> find(node *v, Idx _x, int ly, int ry){
    Idx a = x[v->x_range.first], b = x[v->x_range.second-1];
    if(!v || _x < a || b < _x || ly >= ry) return {0, -1};
    if(_x <= a && b <= _x){
      if(ry - ly >= 1) return {ry - ly, v->info[ly][4]};
      else return {0, -1};
    }
    std::pair<int, int> L = find(v->ch[0], _x, v->info[ly][1], v->info[ry-1][0]);
    if(L.first != 0) return L;
    return find(v->ch[1], _x, v->info[ly][3], v->info[ry-1][2]);
  }
  std::pair<int, int> find(Idx _x, Idx _y){
    int ly_idx = std::lower_bound(y.begin(), y.end(), _y) - y.begin();
    int ry_idx = std::lower_bound(y.begin(), y.end(), _y + 1) - y.begin();
    auto ret = find(root, _x, ly_idx, ry_idx);
    if(ret.first) ret.second = rev_index[ret.second];
    return ret;
  }
  void update_kth(int k, Val val){
    k = sorted_index[k];
    auto [px, py, _, __] = p[k];
    node *v = root;
    update1d(v->_ds, k, val);
    int l = 0, r = x.size(), dep = 0;
    while(r - l > 1){
      int mid = (l + r) / 2;
      v = v->ch[px >= x[mid]];
      update1d(v->_ds, kth_index[dep++][k], val);
      if(px >= x[mid]) l = mid;
      else r = mid;
    }
  }
};
