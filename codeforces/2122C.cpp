/*
    author  : 
    created : 19/07/2025 22:04
    task    : 2122C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n; cin >> n;
    tuple <ll, ll, int> a[n], b[n];
    for (int i = 0; i < n; i++) { auto &[x, y, idx] = a[i]; cin >> x >> y; idx = i+1; swap(x, y); }
    for (int i = 0; i < n; i++) b[i] = a[i], swap(get<0>(b[i]), get<1>(b[i]));
    ll p1 = 0, p2 = 0;
    sort(a, a+n), sort(b, b+n);
    for (auto &[x, y, id] : a) swap(x, y);
    for (auto &[x, y, id] : b) swap(x, y);
    sort(a, a+n/2), sort(a+n/2, a+n);
    sort(b, b+n/2), sort(b+n/2, b+n);
    for (int i = 0; i < n/2; i++) p1 += abs(get<0>(a[i]) - get<0>(a[n-i-1])) + abs(get<1>(a[i]) - get<1>(a[n-i-1]));
    for (int i = 0; i < n/2; i++) p2 += abs(get<0>(b[i]) - get<0>(b[n-i-1])) + abs(get<1>(b[i]) - get<1>(b[n-i-1]));
    if (p1 > p2) {
        for (int i = 0; i < n/2; i++) cout << get<2>(a[i]) << ' ' << get<2>(a[n-i-1]) << '\n';
    } else {
        for (int i = 0; i < n/2; i++) cout << get<2>(b[i]) << ' ' << get<2>(b[n-i-1]) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}