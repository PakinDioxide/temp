/*
    author  : 
    created : 10/08/2025 22:23
    task    : 2131E
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n; ll a[n+1], b[n+1]; a[n] = b[n] = 0;
    for (int i = 0; i < n; i++) cin >> a[i]; for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) if (a[i] != b[i] && (a[i] ^ a[i+1]) != b[i] && (a[i] ^ b[i+1]) != b[i]) { cout << "NO\n"; return; }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}