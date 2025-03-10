#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    cout << "HA";
    int n;
    cin >> n;
    int a[n][n+1];
    for (int i = 0; i < n; i++) {for (int j = 0; j < n; j++) cin >> a[i][j]; a[i][n] = INT_MAX;}
    for (int i = 0; i < n; i++) sort(a[i], a[i]+n);
    int b[n], c[n];
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n+1; i++) {
        vector <pair <int, int>> v;
        for (int j = 0; j < n; j++) {
            while (b[j] <= n && a[j][b[j]] < i) b[j]++;
            if (c[j] || a[j][b[j]] != i) continue;
            v.emplace_back(j, -(a[j][b[j]+1]));
        }
        if (v.size() == 0) {cout << max(1, i-1)<< '\n'; return;}
        c[v[0].first] = 1;
        cout << i << ' ' << v[0].first << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}