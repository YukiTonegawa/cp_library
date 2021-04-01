---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/1Dquery/binary_trie_patricia.test.cpp
    title: verify/1Dquery/binary_trie_patricia.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"1Dquery/binary_trie_patricia.cpp\"\n#include <cassert>\n\
    #include <cstdint>\n#include <algorithm>\n#include <vector>\n\ntemplate<typename\
    \ Key = uint32_t, int KeyLog = 30, int bitlen = sizeof(Key) * 8>\nstruct binary_trie{\n\
    private:\n  struct node{\n    Key k;\n    int l, r, count;\n    int ch[2];\n \
    \   node(Key _k = 0, int _l = 0, int _r = 0):k(_k),l(_l),r(_r),count(0){\n   \
    \   ch[0] = ch[1] = -1;\n    }\n  };\n  int sz = 0;\n  Key xor_lazy;\n  std::vector<node>\
    \ nodes{node()};\n  Key mask(int r){\n    return ((1LL << (r + 1)) - 1);\n  }\n\
    \  int make_node(Key x, int l, int r){\n    nodes.push_back(node(x, l, r));\n\
    \    return ++sz;\n  }\n  int copy_node(int k){\n    nodes.push_back(nodes[k]);\n\
    \    return ++sz;\n  }\n  int next_bit(int v, Key k){\n    Key x = (nodes[v].k\
    \ ^ k) & mask(nodes[v].r);\n    if(bitlen > 32) return (x ? 63 - __builtin_clzll(x)\
    \ : -1);\n    return (x ? 31 - __builtin_clz(x) : -1);\n  }\npublic:\n  binary_trie(){}\n\
    \  int size(int v = 0){\n    return (v == -1 ? 0 : nodes[v].count);\n  }\n  void\
    \ insert(Key x, int k = 1){\n    x ^= xor_lazy;\n    int v = 0, bit = KeyLog -\
    \ 1;\n    while(bit >= 0){\n      nodes[v].count += k;\n      int nxt = (x >>\
    \ bit) & 1;\n      if(nodes[v].ch[nxt]==-1){\n        nodes[v].ch[nxt] = make_node(x,\
    \ 0, bit);\n        nodes[nodes[v].ch[nxt]].count = k;\n        return;\n    \
    \  }\n      v = nodes[v].ch[nxt];\n      int diff_bit = std::max(nodes[v].l -\
    \ 1, next_bit(v, x));\n      if(diff_bit == nodes[v].l - 1){\n        bit = diff_bit;\n\
    \      }else{\n        nxt = (x >> diff_bit) & 1;\n        int tmp = copy_node(v);\n\
    \        nodes[v].l = diff_bit + 1;\n        nodes[tmp].r = diff_bit;\n      \
    \  nodes[v].count += k;\n        nodes[v].ch[!nxt] = tmp;\n        nodes[v].ch[nxt]\
    \ = make_node(x, 0, diff_bit);\n        nodes[nodes[v].ch[nxt]].count = k;\n \
    \       return;\n      }\n    }\n    nodes[v].count += k;\n  }\n  void xor_all(Key\
    \ x){\n    xor_lazy ^= x;\n  }\n  int find(Key x, int v, int bit){\n    v = nodes[v].ch[(x\
    \ >> bit) & 1];\n    if(!v) return 0;\n    int diff_bit = std::max(nodes[v].l\
    \ - 1, next_bit(v, x));\n    if(diff_bit != nodes[v].l - 1) return 0;\n    if(nodes[v].l\
    \ == 0) return nodes[v].count;\n    return find(x, v, diff_bit);\n  }\n  int find(Key\
    \ x){\n    return find(x ^ xor_lazy, 0, KeyLog-1);\n  }\n  int erase(Key x, int\
    \ k, int v, int bit){\n    v = nodes[v].ch[(x >> bit) & 1];\n    if(size(v)==0)\
    \ return 0;\n    int diff_bit = std::max(nodes[v].l - 1, next_bit(v, x));\n  \
    \  if(diff_bit > nodes[v].l - 1) return 0;\n    if(nodes[v].l == 0){\n      k\
    \ = std::min(k, nodes[v].count);\n      nodes[v].count -= k;\n      return k;\n\
    \    }\n    k = erase(x, k, v, diff_bit);\n    nodes[v].count -= k;\n    return\
    \ k;\n  }\n  int erase(Key x, int k = std::numeric_limits<int>::max()){\n    k\
    \ = erase(x ^ xor_lazy, k, 0, KeyLog - 1);\n    nodes[0].count -= k;\n    return\
    \ k;\n  }\n  Key kth_element(int k){\n    assert(k < size());\n    int bit = KeyLog\
    \ - 1, v = 0;\n    while(bit >= 0){\n      int left = (xor_lazy >> bit) & 1;\n\
    \      if(k < size(nodes[v].ch[left])){\n        v = nodes[v].ch[left];\n    \
    \    bit = nodes[v].l - 1;\n      }else{\n        k -= size(nodes[v].ch[left]);\n\
    \        v = nodes[v].ch[!left];\n        bit = nodes[v].l - 1;\n      }\n   \
    \ }\n    return nodes[v].k ^ xor_lazy;\n  }\n  int lower_count(Key k){\n    int\
    \ bit = KeyLog - 1, ret = 0, v = 0;\n    Key kx = k ^ xor_lazy;\n    while(bit\
    \ >= 0){\n      if(v == -1) return ret;\n      if((k >> bit) & 1){\n        ret\
    \ += size(nodes[v].ch[(xor_lazy >> bit) & 1]);\n        v = nodes[v].ch[!((xor_lazy\
    \ >> bit) & 1)];\n      }else{\n        v = nodes[v].ch[(xor_lazy >> bit) & 1];\n\
    \      }\n      if(v != -1){\n        int diff_bit = std::max(nodes[v].l - 1,\
    \ next_bit(v, kx));\n        if(diff_bit != nodes[v].l - 1){\n          ret +=\
    \ ((k >> diff_bit) & 1 ? size(v) : 0);\n          return ret;\n        }\n   \
    \     bit = nodes[v].l - 1;\n      }\n    }\n    return ret;\n  }\n};\n"
  code: "#include <cassert>\n#include <cstdint>\n#include <algorithm>\n#include <vector>\n\
    \ntemplate<typename Key = uint32_t, int KeyLog = 30, int bitlen = sizeof(Key)\
    \ * 8>\nstruct binary_trie{\nprivate:\n  struct node{\n    Key k;\n    int l,\
    \ r, count;\n    int ch[2];\n    node(Key _k = 0, int _l = 0, int _r = 0):k(_k),l(_l),r(_r),count(0){\n\
    \      ch[0] = ch[1] = -1;\n    }\n  };\n  int sz = 0;\n  Key xor_lazy;\n  std::vector<node>\
    \ nodes{node()};\n  Key mask(int r){\n    return ((1LL << (r + 1)) - 1);\n  }\n\
    \  int make_node(Key x, int l, int r){\n    nodes.push_back(node(x, l, r));\n\
    \    return ++sz;\n  }\n  int copy_node(int k){\n    nodes.push_back(nodes[k]);\n\
    \    return ++sz;\n  }\n  int next_bit(int v, Key k){\n    Key x = (nodes[v].k\
    \ ^ k) & mask(nodes[v].r);\n    if(bitlen > 32) return (x ? 63 - __builtin_clzll(x)\
    \ : -1);\n    return (x ? 31 - __builtin_clz(x) : -1);\n  }\npublic:\n  binary_trie(){}\n\
    \  int size(int v = 0){\n    return (v == -1 ? 0 : nodes[v].count);\n  }\n  void\
    \ insert(Key x, int k = 1){\n    x ^= xor_lazy;\n    int v = 0, bit = KeyLog -\
    \ 1;\n    while(bit >= 0){\n      nodes[v].count += k;\n      int nxt = (x >>\
    \ bit) & 1;\n      if(nodes[v].ch[nxt]==-1){\n        nodes[v].ch[nxt] = make_node(x,\
    \ 0, bit);\n        nodes[nodes[v].ch[nxt]].count = k;\n        return;\n    \
    \  }\n      v = nodes[v].ch[nxt];\n      int diff_bit = std::max(nodes[v].l -\
    \ 1, next_bit(v, x));\n      if(diff_bit == nodes[v].l - 1){\n        bit = diff_bit;\n\
    \      }else{\n        nxt = (x >> diff_bit) & 1;\n        int tmp = copy_node(v);\n\
    \        nodes[v].l = diff_bit + 1;\n        nodes[tmp].r = diff_bit;\n      \
    \  nodes[v].count += k;\n        nodes[v].ch[!nxt] = tmp;\n        nodes[v].ch[nxt]\
    \ = make_node(x, 0, diff_bit);\n        nodes[nodes[v].ch[nxt]].count = k;\n \
    \       return;\n      }\n    }\n    nodes[v].count += k;\n  }\n  void xor_all(Key\
    \ x){\n    xor_lazy ^= x;\n  }\n  int find(Key x, int v, int bit){\n    v = nodes[v].ch[(x\
    \ >> bit) & 1];\n    if(!v) return 0;\n    int diff_bit = std::max(nodes[v].l\
    \ - 1, next_bit(v, x));\n    if(diff_bit != nodes[v].l - 1) return 0;\n    if(nodes[v].l\
    \ == 0) return nodes[v].count;\n    return find(x, v, diff_bit);\n  }\n  int find(Key\
    \ x){\n    return find(x ^ xor_lazy, 0, KeyLog-1);\n  }\n  int erase(Key x, int\
    \ k, int v, int bit){\n    v = nodes[v].ch[(x >> bit) & 1];\n    if(size(v)==0)\
    \ return 0;\n    int diff_bit = std::max(nodes[v].l - 1, next_bit(v, x));\n  \
    \  if(diff_bit > nodes[v].l - 1) return 0;\n    if(nodes[v].l == 0){\n      k\
    \ = std::min(k, nodes[v].count);\n      nodes[v].count -= k;\n      return k;\n\
    \    }\n    k = erase(x, k, v, diff_bit);\n    nodes[v].count -= k;\n    return\
    \ k;\n  }\n  int erase(Key x, int k = std::numeric_limits<int>::max()){\n    k\
    \ = erase(x ^ xor_lazy, k, 0, KeyLog - 1);\n    nodes[0].count -= k;\n    return\
    \ k;\n  }\n  Key kth_element(int k){\n    assert(k < size());\n    int bit = KeyLog\
    \ - 1, v = 0;\n    while(bit >= 0){\n      int left = (xor_lazy >> bit) & 1;\n\
    \      if(k < size(nodes[v].ch[left])){\n        v = nodes[v].ch[left];\n    \
    \    bit = nodes[v].l - 1;\n      }else{\n        k -= size(nodes[v].ch[left]);\n\
    \        v = nodes[v].ch[!left];\n        bit = nodes[v].l - 1;\n      }\n   \
    \ }\n    return nodes[v].k ^ xor_lazy;\n  }\n  int lower_count(Key k){\n    int\
    \ bit = KeyLog - 1, ret = 0, v = 0;\n    Key kx = k ^ xor_lazy;\n    while(bit\
    \ >= 0){\n      if(v == -1) return ret;\n      if((k >> bit) & 1){\n        ret\
    \ += size(nodes[v].ch[(xor_lazy >> bit) & 1]);\n        v = nodes[v].ch[!((xor_lazy\
    \ >> bit) & 1)];\n      }else{\n        v = nodes[v].ch[(xor_lazy >> bit) & 1];\n\
    \      }\n      if(v != -1){\n        int diff_bit = std::max(nodes[v].l - 1,\
    \ next_bit(v, kx));\n        if(diff_bit != nodes[v].l - 1){\n          ret +=\
    \ ((k >> diff_bit) & 1 ? size(v) : 0);\n          return ret;\n        }\n   \
    \     bit = nodes[v].l - 1;\n      }\n    }\n    return ret;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: 1Dquery/binary_trie_patricia.cpp
  requiredBy: []
  timestamp: '2021-04-01 21:41:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/1Dquery/binary_trie_patricia.test.cpp
documentation_of: 1Dquery/binary_trie_patricia.cpp
layout: document
redirect_from:
- /library/1Dquery/binary_trie_patricia.cpp
- /library/1Dquery/binary_trie_patricia.cpp.html
title: 1Dquery/binary_trie_patricia.cpp
---
