#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e6+5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll a[mxN], d[mxN], cnt[mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll mx = 0;
    for (int o = 0; o < 10; o++) {
        ll x = a[rng() % n];
        int it = 0;
        for (ll i = 1; i*i <= x; i++) if (x % i == 0) {
            d[it++] = i;
            if (i*i != x) d[it++] = x/i;
        }
        sort(d, d+it);
        for (int i = 0; i < it; i++) cnt[i] = 0;
        for (int i = 0; i < n; i++) cnt[lower_bound(d, d+it, __gcd(a[i], x)) - d]++;
        for (int i = 0; i < it; i++) for (int j = i+1; j < it; j++) if (d[j] % d[i] == 0) cnt[i] += cnt[j];
        for (int i = 0; i < it; i++) if (cnt[i] * 2 >= n) mx = max(mx, d[i]);
    }
    cout << mx << '\n';
}

