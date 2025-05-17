/*
    author  : PakinDioxide
    created : 04/05/2025 20:46
    task    : D2_C
*/

#include <bits/stdc++.h>
#define ll long long

#pragma GCC optimize("O2")
#pragma GCC target("avx2")

using namespace std;

const int mX = 2000000;

int sz, p[mX+5];

int poww(int y) {
    if (y < mX) return p[y];
    if (y == 0) return 1;
    ll k = poww(y/2);
    k *= k;
    if (y % 2 == 1) k <<= 1LL;
    return k % sz;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    // scanf("%lld %lld", &n, &q);
    sz = 2*n+1;
    p[0] = 1;
    for (int i = 1; i < mX; i++) p[i] = (p[i-1] << 1) % sz;
    int idx[sz]; ll a = 1, b = 0; //, sum = 0, sum2 = 1, cnt = 0;
    for (int i = 0, x; i < sz; i++) cin >> x, idx[x] = sz-i-1;
    while (q--) {
        int t, m, k, s;
        // scanf("%lld %lld %lld %lld", &t, &m, &k, &s);
        cin >> t >> m >> k >> s;
        b += t;
        ll c2 = poww(k), c = (c2 - 1)*(m+1)%sz;
        a = (a * c2) % sz, b = (((b * c2)) + c) % sz;
        // sum += t, sum %= sz;
        // sum2 *= poww(2, k, sz), sum2 %= sz;
        // cnt += k;
        // for (auto &e : idx) cout << sz - ((a*e)%sz + b)%sz - 1 << ' ';
        // cout << '\n';

        // SUB K = 0
        // cout << sz - ((((sum2*idx[s])%sz) + sum) % sz) - 1 << ' ';

        // SUB K > 0, T = 0, M = 0
        // cout << sz - ((((sum2*idx[s])%sz) + sum + poww(2, cnt, sz) - 1 + sz) % sz) - 1 << ' ';

        // SUB ALL
        // printf("%lld ", sz - ((a*idx[s]) + b)%sz - 1);
        cout << sz - ((a*idx[s])%sz + b)%sz - 1 << ' ';
    }
    cout << '\n';
    // printf("\n");
}

/*
0 2 4 6 1 3 5 
0 4 1 5 2 6 3
*/