#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m, l, temp;
vector <tuple <int, int, ll>> adj[200005];
vector <pair <ll, ll>> a;

void dfs(int u, ll x, ll y) {
    if (u == n) {
        a.emplace_back(y, x);
    } else {
        for (auto [v, s, w] : adj[u]) {
            dfs(v, x + (s == 1 ? w : 0), y + (s == 2 ? w : 0));
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> l;
    while (l--) cin >> temp;
    while (m--) {
        int u, v, s;
        ll w;
        cin >> u >> v >> s >> w;
        adj[u].emplace_back(v, s, w);
    }
    dfs(1, 0, 0);
    sort(a.begin(), a.end());
    set <pair <ll, ll>> s;
    ll d = LLONG_MAX;
    int k = 0;
    for (int i = 0; i < a.size(); i++) {
        auto [x, y] = a[i];
        ll k = ceil(sqrt(d));
        while (k < i && x - a[k].first > k) s.erase(s.find({a[k].second, a[k].first})), k++;
        auto idx = s.lower_bound({y-k, 0});
        while (idx != s.end()) {
            auto [yy, xx] = *idx;
            if (yy > y+k) break;
            d = min(d, (xx-x)*(xx-x) + (yy-y)*(yy-y));
            idx++;
        }
        s.emplace(y, x);
    }
    cout << d;
}