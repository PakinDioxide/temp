/*
    author  : PakinDioxide
    created : 08/05/2025 11:04
    task    : JOI19_ho_t1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) a[i][j] = (s[j] == 'J' ? 0 : s[j] == 'O' ? 1 : 2);
    }
    vector <int> r[n], c[m];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] == 1) r[i].emplace_back(j);
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (a[j][i] == 2) c[i].emplace_back(j);
    ll ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] == 0) {
        ll it1 = upper_bound(r[i].begin(), r[i].end(), j) - r[i].begin(), it2 = upper_bound(c[j].begin(), c[j].end(), i) - c[j].begin();
        ans += ((ll) r[i].size() - it1) * ((ll) c[j].size() - it2);
    }
    cout << ans << '\n';
}