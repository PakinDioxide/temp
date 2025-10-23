/*
    author  : 
    created : 21/09/2025 16:13
    task    : 1809C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    k = n*(n+1)/2 - k;
    int a[n]; for (auto &e : a) e = 2;
    for (int i = 0; i < n; i++) {
        int x = min((n-i), k);
        if (x) a[i] = 1 - 2*x;
        k -= x;
    }
    for (auto &e : a) cout << e << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}