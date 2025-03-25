/*
    author  : PakinDioxide
    created : 25/03/2025 17:43
    task    : 547B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll a[n], par[n], c[n], ans[n+1];
    memset(ans, 0, sizeof(ans));
    iota(par, par+n, 0);
    for (auto &e : a) cin >> e, ans[1] = max(ans[1], e);
    for (int i = 0; i < n; i++) c[i] = 1;
    priority_queue <tuple <ll, int, int>> q;
    for (int i = 0; i < n-1; i++) q.emplace(min(a[i], a[i+1]), i, i+1);
    function <ll(ll)> fi = [&] (ll x) {
        if (par[x] != x) return par[x] = fi(par[x]);
        return x;
    };
    while (!q.empty()) {
        auto [w, u, v] = q.top();
        q.pop();
        c[fi(v)] += c[fi(u)];
        par[fi(u)] = fi(v);
        ans[c[fi(v)]] = max(ans[c[fi(v)]], w);
    }
    for (int i = n-1; i > 0; i--) ans[i] = max(ans[i], ans[i+1]);
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
}