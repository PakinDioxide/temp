/*
    author  : PakinDioxide
    created : 16/03/2025 01:00
    task    : a
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int l = 1, r = n;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) cout << r-- << ' ';
        else cout << l++ << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}