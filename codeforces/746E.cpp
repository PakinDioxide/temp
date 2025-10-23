#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n; ll m; cin >> n >> m;
    ll a[n], co = ceil(m/2.0), ce = m/2;
    unordered_set <ll> so, se;
    for (auto &e : a) {
        cin >> e;
        if (e % 2 == 1) so.emplace(e);
        else se.emplace(e);
    }
    for (auto &e : so) if (e <= m) co--;
    for (auto &e : se) if (e <= m) ce--;
    int no = max(0, n/2 - (int) so.size()), ne = max(0, n/2 - (int) se.size());
    if (no > co || ne > ce) { cout << -1 << '\n'; return 0; }
    cout << no + ne << '\n';
    ll io = 1, ie = 2, cco = 0, cce = 0;
    unordered_map <ll, int> vis, mp;
    int cc = 0;
    for (auto &e : so) if (cc < n/2) mp[e] = 1, cc++; cc = 0;
    for (auto &e : se) if (cc < n/2) mp[e] = 1, cc++;
    for (auto &e : a) {
        if (!vis[e] && ((e % 2 == 1 && cco < n/2) || (e % 2 == 0 && cce < n/2))) {
            vis[e] = 1, cout << e << ' ';
            cco += (e % 2);
            cce += !(e % 2);
        } else {
            if (no > 0) {
                while (vis[io] || mp[io]) io += 2;
                cout << io << ' ';
                vis[io] = 1;
                no--;
                cco++;
            } else {
                while (vis[ie] || mp[ie]) ie += 2;
                cout << ie << ' ';
                vis[ie] = 1;
                cce++;
            }
        }
    }
    cout << '\n';
}