/*
    author  : PakinDioxide
    created : 24/05/2025 21:35
    task    : 2110A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    int a[n], l0 = 0, l1 = 0, r0 = 0, r1 = 0;
    for (auto &e : a) cin >> e;
    sort(a, a+n);
    for (auto &e : a) e %= 2;
    while (l0 < n && a[l0] != 0) l0++;
    while (l1 < n && a[l1] != 1) l1++;
    while (r0 < n && a[n-1-r0] != 0) r0++;
    while (r1 < n && a[n-1-r1] != 1) r1++;
    cout << min(l0+r0, l1+r1) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}