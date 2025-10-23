/*
    author  : 
    created : 30/06/2025 21:58
    task    : 1760C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    int p = INT_MIN, q = INT_MIN;
    int a[n]; for (auto &e : a) {
        cin >> e;
        if (e >= p) q = p, p = e;
        else if (e >= q) q = e;
    }
    for (auto &e : a) cout << (e == p ? e-q : e-p) << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}