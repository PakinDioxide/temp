#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    int a[m+1], b[m+1], clear[n+1]; memset(clear, 0, sizeof(clear));
    vector <int> c[n+1];
    for (int i = 1; i <= m; i++) cin >> a[i] >> b[i];
    for (int i = 1; i <= m; i++) if (a[i] != b[i]) {
        if (b[i]) c[b[i]].emplace_back(-i);
        else if (a[i]) c[a[i]].emplace_back(i);
    }
    for (int i = 1; i <= m; i++) if (a[i] == b[i]) clear[a[i]] = 1;
    vector <pair <int, int>> v;
    queue <int> q;
    for (int i = 1; i <= n; i++) q.emplace(i);
    while (q.size()) {
        int e = q.front(); q.pop();
        if (clear[e]) continue;
        if (c[e].size() == 2 && (c[e][0] > 0 || c[e][1] > 0)) {
            if (c[e][0] > c[e][1]) swap(c[e][0], c[e][1]);
            v.emplace_back(abs(c[e][0]), c[e][1]);
            b[c[e][1]] = e;
            if (c[e][0] < 0) b[abs(c[e][0])] = 0;
            else a[c[e][0]] = 0;
            clear[e] = 1;
            c[a[abs(c[e][0])]].emplace_back(abs(c[e][0]));
            q.emplace(a[abs(c[e][0])]);
        }
    }
    for (int i = 1; i <= m; i++) cout << b[i] << ' '; cout << '\n';
    for (int i = 1; i <= m; i++) cout << a[i] << ' '; cout << '\n';
    cout << v.size() << '\n';
    for (auto &[x, y] : v) cout << x << ' ' << y << '\n';
}
