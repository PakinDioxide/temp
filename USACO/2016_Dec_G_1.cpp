/*
    author  : PakinDioxide
    created : 03/05/2025 09:38
    task    : 2016_Dec_G_1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1005;

int n, par[mxN];
pair <ll, ll> a[mxN];
vector <tuple <ll, int, int>> V;
ll ans = 0, cnt = 0, it = 0;

int fi(int x) { return x == par[x] ? x : par[x] = fi(par[x]); }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> n;
    iota(par, par+n+1, 0);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) V.emplace_back((a[i].first-a[j].first)*(a[i].first-a[j].first) + (a[i].second-a[j].second) * (a[i].second - a[j].second), i, j);
    sort(V.begin(), V.end());
    while (cnt < n-1) {
        auto [w, u, v] = V[it++];
        if (fi(u) == fi(v)) continue;
        par[fi(v)] = fi(u);
        cnt++;
        ans = max(ans, w);
    }
    cout << ans << '\n';
}