#include "inv.h"
#include <bits/stdc++.h>
#define ll long long

ll mod;

void init(int p) {
    mod = p;
}

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    ll k = poww(x, y/2);
    k *= k, k %= mod;
    if (y % 2 == 1) k *= x, k %= mod;
    return k;
}

int inv(int x) {
    return poww(x, mod-2);
}
