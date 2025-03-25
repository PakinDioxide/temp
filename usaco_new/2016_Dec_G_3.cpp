/*
    author  : PakinDioxide
    created : 25/03/2025 02:43
    task    : 2016_Dec_G_3
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
    ll n, sx, sy, ex, ey;
    vector <ll> cx, cy;
    cin >> n;
    pair <ll, ll> a[n+2];
    cin >> a[0].first >> a[0].second >> a[n+1].first >> a[n+1].second;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    for (auto &[x, y] : a) cx.push_back(x), cy.push_back(y);
    sort(cx.begin(), cx.end()), sort(cy.begin(), cy.end());
    for (auto &[x, y] : a) x = lower_bound(cx.begin(), cx.end(), x) - cx.begin(), y = lower_bound(cy.begin(), cy.end(), y) - cy.begin();
    vector <int> ax[n+5], ay[n+5];
    for (int i = 0; i <= n+1; i++) ax[a[i].first].push_back(i), ay[a[i].second].push_back(i);
    priority_queue <pair <int, int>> q;
    int dis[n+5];
    for (int i = 0; i < n+5; i++) dis[i] = INT_MAX;
    dis[0] = 0;
    q.emplace(0, 0);
    while (!q.empty()) {
        auto [w, u] = q.top();
        q.pop();
        w=-w;
        if (dis[u] != w) continue;
        auto [x, y] = a[u];
        for (auto v : ax[x]) if (dis[v] > w+1) q.emplace(-(dis[v] = w+1), v);
        for (auto v : ay[y]) if (dis[v] > w+1) q.emplace(-(dis[v] = w+1), v);
    }
    cout << (dis[n+1] == INT_MAX ? -1 : dis[n+1]-1) << '\n';
}