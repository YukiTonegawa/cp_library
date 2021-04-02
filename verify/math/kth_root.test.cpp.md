---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/kth_root.cpp
    title: math/kth_root.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://old.yosupo.jp/problem/kth_root_integer
    links:
    - https://old.yosupo.jp/problem/kth_root_integer
  bundledCode: "#line 1 \"verify/math/kth_root.test.cpp\"\n#include <iostream>\n#include\
    \ <limits>\n#include <vector>\n#include <cmath>\n#include <cassert>\n#define PROBLEM\
    \ \"https://old.yosupo.jp/problem/kth_root_integer\"\n#line 5 \"math/kth_root.cpp\"\
    \n\nuint64_t kth_root_stable(uint64_t x, uint64_t k){\n  if(x==0) return 0;\n\
    \  if(k==1||x==1) return x;\n  if(k>=64) return 1;\n  uint64_t l = 1, r = x;\n\
    \  const static uint64_t threshold = std::numeric_limits<uint64_t>::max();\n \
    \ while(r-l>1){\n    bool f = false;\n    uint64_t mid = l + ((r - l) >> 1), z\
    \ = 1;\n    uint64_t lim = threshold / mid;\n    for(int i=0;i<k;i++){\n     \
    \ if(z > lim){\n        f = true;\n        break;\n      }\n      z *= mid;\n\
    \    }\n    if(f | (z > x)) r = mid;\n    else l = mid;\n  }\n  return l;\n}\n\
    \nuint64_t kth_root_fast(uint64_t x, uint64_t k){\n  if(x<=1) return (k==0?1:x);\n\
    \  if(k<=2) return (k<=1?k==0?1:x:sqrtl(x));\n  if(k>=64||!(x>>k)) return 1;\n\
    \  const static int sz[8] = {40,31,27,24,22,21,20,19};\n  static std::vector<std::vector<uint64_t>>\
    \ table;\n  if(table.empty()){\n    table.resize(40);\n    for(int i=0;i<40;i++)for(uint64_t\
    \ j=0;j<8&&sz[j]>i;j++)table[i].push_back((i==0?uint64_t(1):table[i-1][j])*(j+3));\n\
    \  }\n  if(k>=19){\n    int ans = 10;\n    for(;ans>2;ans--){\n      if(sz[ans-3]<k\
    \ || table[k-1][ans-3] > x) continue;\n      return ans;\n    }\n    return 2;\n\
    \  }\n  uint64_t r = (k!=3?pow(x, (1.0 + 1e-6)/k):cbrt(x)+1);\n  const static\
    \ uint64_t threshold = std::numeric_limits<uint64_t>::max();\n  while(true){\n\
    \    uint64_t lim = threshold / r, z = 1;\n    for(int i=0;i<k;i++, z*=r) if(z\
    \ > lim) goto upper;\n    if(z > x) upper:r--;\n    else break;\n  }\n  return\
    \ r;\n}\n#line 8 \"verify/math/kth_root.test.cpp\"\n\nint main(){\n\tint T;scanf(\"\
    %d\", &T);\n\tfor(int i=0;i<T;i++) {\n    uint64_t x, k;scanf(\"%llu %llu\", &x,\
    \ &k);\n    uint64_t ans1 = kth_root_fast(x, k);\n    uint64_t ans2 = kth_root_stable(x,\
    \ k);\n    assert(ans1 == ans2);\n    printf(\"%llu\\n\", ans1);\n  }\n}\n"
  code: "#include <iostream>\n#include <limits>\n#include <vector>\n#include <cmath>\n\
    #include <cassert>\n#define PROBLEM \"https://old.yosupo.jp/problem/kth_root_integer\"\
    \n#include \"../../math/kth_root.cpp\"\n\nint main(){\n\tint T;scanf(\"%d\", &T);\n\
    \tfor(int i=0;i<T;i++) {\n    uint64_t x, k;scanf(\"%llu %llu\", &x, &k);\n  \
    \  uint64_t ans1 = kth_root_fast(x, k);\n    uint64_t ans2 = kth_root_stable(x,\
    \ k);\n    assert(ans1 == ans2);\n    printf(\"%llu\\n\", ans1);\n  }\n}\n"
  dependsOn:
  - math/kth_root.cpp
  isVerificationFile: true
  path: verify/math/kth_root.test.cpp
  requiredBy: []
  timestamp: '2021-04-03 04:32:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/math/kth_root.test.cpp
layout: document
redirect_from:
- /verify/verify/math/kth_root.test.cpp
- /verify/verify/math/kth_root.test.cpp.html
title: verify/math/kth_root.test.cpp
---
