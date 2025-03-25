/*
    author  : PakinDioxide
    created : 15/03/2025 01:30
    task    : 782B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    long double x[n], v[n];
    for (auto &e : x) cin >> e;
    for (auto &e : v) cin >> e;
    long double l = 0, r = 1e9, ans = 0;
    while (l <= r) {
        long double m = (l+r)/2;
        vector <pair <long double, int>> V;
        for (int i = 0; i < n; i++) {
            V.emplace_back(x[i]-v[i]*m, 0);
            V.emplace_back(x[i]+v[i]*m, 1);
        }
        sort(V.begin(), V.end());
        int cnt = 0, mx = 0;
        for (auto [x, y] : V) cnt += (y == 0 ? 1 : -1), mx = max(cnt, mx);
        if (mx == n) ans = m, r = m - 1e-7;
        else l = m + 1e-7;
    }
    cout << setprecision(7) << ans << '\n';
}