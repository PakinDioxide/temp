#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll m, a, b, c;
    cin >> m >> a >> b >> c;
    ll k = min(m, a) + min(m, b);
    cout << k + max(0LL, min(c, 2*m-k)) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}