/*
    author  : PakinDioxide
    created : 22/09/2025 17:57
    task    : d
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    ll p[n], l[m], r[m], c[m];
    for (auto &e : p) cin >> e, e = -e;
    for (auto &e : l) cin >> e;
    for (auto &e : r) cin >> e;
    for (auto &e : c) cin >> e;
    if (k == 1) {
        vector <pair <ll, ll>> v;
        for (int i = 0; i < m; i++) v.emplace_back(l[i], c[i]), v.emplace_back(r[i]+1, -c[i]);
        ll c = 0, ans = LLONG_MIN;
        sort(v.begin(), v.end());
        for (auto &e : p) ans = max(e, ans);
        for (int i = 0; i < v.size(); i++) {
            c += v[i].second;
            if (v[i].first >= n) break;
            if (i == v.size()-1 || v[i].first != v[i+1].first) {
                ans = max(ans, c + p[v[i].first]);
            }
        }
        cout << ans << '\n';
        return 0;
    } else if (n <= 10) {
        ll ans = LLONG_MIN, cost = 0;
        vector <int> P;
        function <void(int)> solve = [&] (int idx) {
            ll d = cost;
            if (idx == n && P.size() != k) return;
            else if (idx == n) {
                for (int i = 0; i < m; i++) {
                    int ok = 0;
                    for (auto &e : P) if (l[i] <= e && e <= r[i]) { ok = 1; break; }
                    if (ok) d += c[i];
                }
                ans = max(ans, d);
                return;
            }
            if (P.size() < k) {
                P.emplace_back(idx);
                cost += p[idx];
                solve(idx+1);
                P.pop_back();
                cost -= p[idx];
            }
            solve(idx+1);
        };
        solve(0);
        cout << ans << '\n';
        return 0;
    }
    for (int i = 0; i < m; i++) p[l[i]] += c[i];
    sort(p, p+n);
    ll cnt = 0;
    for (int i = n-1; i >= n-k; i--) cnt += p[i];
    cout << cnt << '\n';
}