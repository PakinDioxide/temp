/*
    author  : 
    created : 30/06/2025 22:05
    task    : 1699B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < m; j += 2) cout << (j/2 % 2 == i/2 % 2 ? "0 1 " : "1 0 ");
        cout << '\n';
        for (int j = 0; j < m; j += 2) cout << (j/2 % 2 != i/2 % 2 ? "0 1 " : "1 0 ");
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}