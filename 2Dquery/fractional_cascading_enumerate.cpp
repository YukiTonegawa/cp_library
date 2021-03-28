#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <array>

template<typename T, typename Idx = int>
struct fractional_cascading_enumerate{
private:
  using point = std::tuple<Idx, Idx, T>;
  std::vector<Idx> x, y;
  std::vector<point> p;
  struct node{
    std::pair<int, int> x_range;
    node *ch[2];
    std::vector<int> list;
    std::vector<std::array<int, 4>> next_idx;
    node(){ch[0] = ch[1] = nullptr;}
  };
  node *root;
  void build(node *v, int l, int r){
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
public:
  void build(const std::vector<point> &points){
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
  fractional_cascading_enumerate(const std::vector<point> &points){
    build(points);
  }
  void query(node *v, Idx lx, Idx rx, int ly, int ry, std::vector<point> &ret){
    Idx a = x[v->x_range.first], b = x[v->x_range.second-1];
    if(!v || rx <= a || b < lx || lx >= rx || ly >= ry) return;
    if(lx <= a && b < rx){
      for(int i=ly;i<ry;i++) ret.push_back(p[v->list[i]]);
      return;
    }
    query(v->ch[0], lx, rx, v->next_idx[ly][1], v->next_idx[ry-1][0], ret);
    query(v->ch[1], lx, rx, v->next_idx[ly][3], v->next_idx[ry-1][2], ret);
  }
  std::vector<point> query(Idx lx, Idx rx, Idx ly, Idx ry){
    int ly_idx = std::lower_bound(y.begin(), y.end(), ly) - y.begin();
    int ry_idx = std::lower_bound(y.begin(), y.end(), ry) - y.begin();
    std::vector<point> ret;
    query(root, lx, rx, ly_idx, ry_idx, ret);
    return ret;
  }
};
