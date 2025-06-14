/*
    author  : PakinDioxide
    created : 24/05/2025 21:43
    task    : 2110C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    int d[n]; for (auto &e : d) cin >> e;
    int l[n], r[n], p[n], pm[n];
    p[0] = (d[0] == -1 ? 1 : d[0]);
    for (int i = 1; i < n; i++) p[i] = p[i-1] + max(0, (d[i] == -1 ? 1 : d[i]));
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
    int mn[n], mx[n];
    mn[0] = l[0]; for (int i = 1; i < n; i++) mn[i] = max(l[i], mn[i-1]);
    mx[n-1] = r[n-1]; for (int i = n-2; i >= 0; i--) mx[i] = min(r[i], mx[i+1]);
    for (int i = 0; i < n; i++) if (mn[i] > mx[i]) { cout << -1 << '\n'; return; }

    pm[n-1] = mn[n-1] - p[n-1];
    for (int i = n-2; i >= 0; i--) pm[i] = max(pm[i+1], mn[i] - p[i]);

    int ans[n], h = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] == -1) {
            // cout << "HI " << pm[i] + p[i-1] << '\n';
            if (h <= pm[i] + (i > 0 ? p[i-1] : 0)) ans[i] = 1, h++;
            else ans[i] = 0;
        } else ans[i] = d[i], h += d[i];
        // cout << "I " << i << ' ' << h << '\n';
        if (h < mn[i] || h > mx[i]) { cout << -1 << '\n'; return; }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
we want to find minimum distance

if h + free distance[i][x] + d[i][x] == l[x] then d[i] = 1
if h == min(l[x] - fee distance[i][x] - d[i][x])
else d[i] = 0

*/