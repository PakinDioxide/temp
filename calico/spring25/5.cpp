/*
    author  : PakinDioxide
    created : 27/04/2025 06:47
    task    : 5
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    ll ans = 0;
    int p[n+1], k[n+2];
    p[0] = 0;
    k[n+1] = n+1;
    for (int i = 1; i <= n; i++) p[i] = p[i-1] + (s[i] == 'u');
    for (int i = n; i >= 1; i--) k[i] = min(k[i+1], (s[i] == 'w' ? i : INT_MAX));
    for (int i = 1; i <= n; i++) {
        if (s[i] != 'u' || k[i] > n) continue;
        ans += p[n] - p[k[i]];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}