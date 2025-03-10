#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, b, c, cnt = n+1;
    cin >> n >> b >> c;
    if (b == 0) {
        if (n - c > 2) cnt = n+1;
        else cnt = n - (n-1 + (c >= n));
    } else cnt = (ll) min((ll) max(0LL, (ll) ceil((long double)(n-c)/b)), n);
    cout << n - cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}