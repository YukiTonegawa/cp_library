#include <set>
#include <unordered_map>
#include "../2Dquery/offline_point_add_rectangle_sum.cpp"

template<typename Idx = int, typename Val = int>
struct offline_point_set_range_types{
private:
  using query = std::tuple<int, int, Idx, Idx, Val>;//query_type, index, l, r, value
  std::vector<query> q;
  int qs = 0;
public:
  offline_point_set_range_types(){}
  void set_val(Idx i, Val v){
    q.push_back(std::make_tuple(0, 0, i, 0, v));
  }
  void get_types(Idx l, Idx r){
    q.push_back(std::make_tuple(1, qs++, l, r, 0));
  }
  std::vector<int> solve(){
    point_add_rectangle_sum<Idx, int> rect;
    std::vector<std::set<Idx>> table;
    std::vector<Val> v;
    std::vector<int> ans(qs, 0);
    std::unordered_map<Idx, int> dic;
    for(int i=0;i<q.size();i++) if(std::get<0>(q[i]) == 0) v.push_back(std::get<4>(q[i]));
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    table.resize(v.size());
    for(int i=0;i<q.size();i++){
      if(std::get<0>(q[i]) == 0){
        Idx index = std::get<2>(q[i]);
        Val val = std::get<4>(q[i]);
        auto dup = dic.find(index);
        if(dup != dic.end()){
          int t = lower_bound(v.begin(), v.end(), dup->second) - v.begin();
          auto itr = table[t].find(index);
          auto itr_nxt = itr;
          itr_nxt++;
          if(itr != table[t].begin() && itr_nxt != table[t].end()){
            auto itr_pre = itr;itr_pre--;
            rect.add_point(*itr_pre, *itr_nxt, 1);
            rect.add_point(*itr_pre, *itr, -1);
            rect.add_point(*itr, *itr_nxt, -1);
          }else if(itr != table[t].begin()){
            auto itr_pre = itr;itr_pre--;
            rect.add_point(*itr_pre, *itr, -1);
          }else if(itr_nxt != table[t].end()){
            rect.add_point(*itr, *itr_nxt, -1);
          }
          table[t].erase(itr);
          dic.erase(index);
        }
        int t = lower_bound(v.begin(), v.end(), val) - v.begin();
        dic.emplace(index, t);
        table[t].insert(index);
        auto itr = table[t].find(index);
        auto itr_nxt = itr;
        itr_nxt++;
        if(itr != table[t].begin() && itr_nxt != table[t].end()){
          auto itr_pre = itr;itr_pre--;
          rect.add_point(*itr_pre, *itr_nxt, -1);
          rect.add_point(*itr_pre, *itr, 1);
          rect.add_point(*itr, *itr_nxt, 1);
        }else if(itr != table[t].begin()){
          auto itr_pre = itr;itr_pre--;
          rect.add_point(*itr_pre, *itr, 1);
        }else if(itr_nxt != table[t].end()){
          rect.add_point(*itr, *itr_nxt, 1);
        }
      }else{
        Idx l = std::get<2>(q[i]), r = std::get<3>(q[i]);
        rect.add_query(l, r, l, r);
      }
    }
    auto rect_sum = rect.solve();
    for(int i=0;i<q.size();i++){
      if(std::get<0>(q[i]) == 1){
        auto [_, index, l, r, __] = q[i];
        ans[index] = r - l - rect_sum[index];
      }
    }
    return ans;
  }
};
