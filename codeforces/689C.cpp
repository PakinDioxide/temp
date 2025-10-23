#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll m; cin >> m;
    ll l = 0, r = 1e18, ans = -1;
    while (l <= r) {
        ll x = l + (r-l)/2, cnt = 0;
        for (ll k = 2; k*k*k <= x; k++) cnt += x / (k * k * k);
        if (cnt > m) r = x-1;
        else if (cnt == m) r = x-1, ans = x;
        else l = x+1;
    }
    cout << ans << '\n';
}

/*
if start at x
k^3x <= n

if at n, 
*/