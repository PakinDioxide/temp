/*
    author  : 
    created : 21/06/2025 21:35
    task    : 2120A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int solve() {
    int n = 3;
    pair <int, int> a[n];
    for (auto &[x, y] : a) cin >> x >> y;
    sort(a, a+n);
    if (a[0].first + a[1].first == a[2].first && a[0].second == a[1].second && a[0].second + a[2].second == a[2].first) return 1;
    if (a[0].first == a[1].first && a[1].first == a[2].first && a[0].second + a[1].second + a[2].second == a[2].first) return 1;
    for (auto &[x, y] : a) swap(x, y);
    if (a[0].first + a[1].first == a[2].first && a[0].second == a[1].second && a[0].second + a[2].second == a[2].first) return 1;
    if (a[0].first == a[1].first && a[1].first == a[2].first && a[0].second + a[1].second + a[2].second == a[2].first) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) cout << (solve() ? "YES\n" : "NO\n");
}