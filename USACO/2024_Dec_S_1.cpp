#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    ll a[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll p[n+1], s[n+2]; memset(p, 0, sizeof(p)); memset(s, 0, sizeof(s));
    for (int i = 1; i <= n; i++) p[i] = p[i-1] + a[i];
    for (int i = n; i >= 1; i--) s[i] = s[i+1] + a[i];
    ll mx = 0;
    for (int i = 0; i <= (n-1)/2; i++) mx = max(mx, p[i] + s[n - ((n-1)/2 - i) + 1]);
    cout << p[n] - mx << ' ' << mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}