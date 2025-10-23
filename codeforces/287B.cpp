#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll n, k; cin >> n >> k;
    k--;
    n--;
    ll c = k*(k+1)/2;
    n = c-n;
    n *= 2;
    ll ans = -1, l = 0, r = k;
    while (l <= r) {
        ll x = l + (r-l)/2;
        if (x*(x+1) <= n) ans = x, l = x+1;
        else r = x-1;
    }
    if ((n - ans*(ans+1))/2 <= ans) cout << k - ans << '\n';
    else cout << -1 << '\n';
}
