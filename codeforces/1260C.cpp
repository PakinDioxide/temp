#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll x, y, k; cin >> x >> y >> k;
    if (x > y) swap(x, y);
    ll p = __gcd(x, y);
    if (k > ceil((double) (y-p)/x)) cout << "OBEY\n";
    else cout << "REBEL\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

