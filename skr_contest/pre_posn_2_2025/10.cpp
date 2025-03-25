/*
    author  : PakinDioxide
    created : 17/03/2025 21:23
    task    : 10
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 1e9+7;

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    ll k = poww(x, y/2);
    k *= k, k %= mod;
    if (y % 2 == 1) k *= x, k %= mod;
    return k;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll cnt[400005];
    for (int i = 0; i < n; i++) {
        ll a, p;
        cin >> a >> p;
        ll c[400005];
        memset(c, 0, sizeof(c));
        for (int i = 2; i < 400005; i++) {
            if (a == 1) break;
            while (a % i == 0) c[i]++, a /= i;
            cnt[i] = max(cnt[i], c[i]*p);
        }
    }
    ll ans = 1;
    for (int i = 2; i < 400005; i++) {
        ans *= poww(i, cnt[i]);
        ans %= mod;
    }
    cout << ans << '\n';
}