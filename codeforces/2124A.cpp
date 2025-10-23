/*
    author  : 
    created : 06/07/2025 21:35
    task    : 2124A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    int a[n]; for (auto &e : a) cin >> e;
    for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) if (a[i] > a[j]) {
        cout << "YES\n" << 2 << '\n' << a[i] << ' ' << a[j] << '\n';
        return;
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}