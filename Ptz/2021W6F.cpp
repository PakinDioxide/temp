#include <bits/stdc++.h>
#define ll long long

using namespace std;

#define P complex <ll>
#define x real()
#define y imag()

const ll mod = 998244353;

ll poww(ll a, ll b) {
    if (b == 0) return 1;
    ll k = poww(a, b/2);
    k *= k, k %= mod;
    if (b % 2 == 1) k *= a, k %= mod;
    return k;
}

ll inv(ll k) { return poww(k, mod-2); }

ll cross(P a, P b) { return (conj(a)*b).y; }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    ll a[n]; for (auto &e : a) cin >> e;
    P A[n]; for (int i = 0; i < n; i++) A[i] = {i, a[i]};
    vector <int> hull;
    int sz = 0;
    for (int i = 0; i < n; i++) {
        P k = A[i];
        while (sz >= 2 && cross(A[hull[sz-1]]-A[hull[sz-2]], k-A[hull[sz-1]]) > 0) hull.pop_back(), sz--;
        sz++, hull.emplace_back(i);
    }
    ll ans = 0;
    for (int i = 0; i < sz-1; i++) {
        int l = hull[i], r = hull[i+1];
        ans += (a[l] * inv(n)) % mod;
        ans %= mod;
        for (int j = l+1; j < r; j++) {
            ll val = (((r-i)*a[l] + (i-l)*a[r]) * inv(r-l)) % mod;
            ans += val * inv(n);
            ans %= mod;
        }
    }
    ans += (a[n-1] * inv(n)) % mod;
    ans %= mod;
    cout << ans << '\n';
}

