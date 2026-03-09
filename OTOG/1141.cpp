#include <bits/stdc++.h>
#define ll __uint128_t
// #define ll long long

using namespace std;

ll N, sz = 1;

void init(int n) {
    N = n;
    for (int i = 0; i < n; i++) sz *= 4;
}

ll query(ll q) {
    vector <int> v;
    q--;
    while (q) {
        v.emplace_back(q % 4);
        q /= 4;
    }
    while (v.size() < N) v.emplace_back(0);
    ll ans = 0, ss = sz;
    while (!v.empty()) {
        int x = v.back();
        ss /= 4;
        if (x == 1) ans += ss*2;
        else if (x == 2) ans += ss*3;
        else if (x == 3) ans += ss;
        v.pop_back();
    }
    return ans+1;
}
