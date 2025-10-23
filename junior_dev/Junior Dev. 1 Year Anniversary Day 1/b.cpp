/*
    author  : PakinDioxide
    created : 22/09/2025 17:57
    task    : b
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int mod() {
    string n; cin >> n;
    ll kk = 0;
    for (auto &e : n) kk*=10, kk += (e - '0') % 6, kk %= 6;
    return kk;
}

const ll MOD = 1e9+7;

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    ll k = poww(x, y/2);
    k *= k, k %= MOD;
    if (y % 2 == 1) k *= x, k %= MOD;
    return k;
}

ll ncr(ll x, ll y) {
    ll c = 1;
    for (int i = 1; i <= x; i++) c *= i, c %= MOD;
    for (int i = 1; i <= y; i++) c *= poww(i, MOD-2), c %= MOD;
    for (int i = 1; i <= x-y; i++) c *= poww(i, MOD-2), c %= MOD;
    return c;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int kk = mod();
    int m, k; cin >> m >> k;
    int C[6] = {5, 1, 3, 2, 6, 4};
    int cur = 0;
    for (int i = 1; i <= kk; i++) cur += C[i], cur %= 7;
    ll a[6]; memset(a, 0, sizeof(a));
    while (m--) { int x = mod(); a[x]++; cur -= C[x]; cur += 7; cur %= 7; }
    int need = (7 - cur) % 7;
    // cout << need << '\n';
    for (int i = 0; i < 6; i++) if (C[i] == need) { cout << a[i] << '\n'; return 0; }
    cout << 1 << '\n';
    // cout << need << '\n';
    // ll ans = 0;
    // for (int p = 0; p <= a[0]; p++) for (int q = 0; q <= a[1]; q++) for (int r = 0; r <= a[2]; r++) {
    //     if (p + q + r > k) break;
    //     if ((C[0] * p + C[1] * q + C[2] * r) % 7 == need) cout << p << ' ' << q << ' ' << r << '\n', ans += (((ncr(a[0], p) * ncr(a[1], q)) % MOD) * ncr(a[2], r)) % MOD, ans %= MOD;
    // }
    // cout << ans << '\n';
}

/*


loop
1
3
2
6
4
533
1
*/