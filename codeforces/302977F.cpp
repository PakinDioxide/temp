/*
    author  : 
    created : 23/06/2025 20:13
    task    : 302977F
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, k; cin >> n >> k;
    ll ans = 1;
    for (int i = 2; i <= k; i++) {
        ll cnt = 1;
        for (int j = 0; j < i; j++) cnt *= (n-j);
        for (int j = 1; j <= i; j++) cnt /= j;
        if (i == 2) cnt *= 1;
        else if (i == 3) cnt *= 2;
        else cnt *= 9;
        ans += cnt;
    }
    cout << ans << '\n';
}