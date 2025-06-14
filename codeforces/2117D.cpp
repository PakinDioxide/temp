/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double

using namespace std;

void solve() {
    int n; cin >> n; ll sum = 0, a[n];
    for (auto &e : a) cin >> e, sum += e;
    ll k = n*(n+1)/2;
    if (sum % k != 0) { cout << "NO\n"; return; }
    k = sum/k;
    // cout << "K " << k << '\n';
    ll mn = LLONG_MAX, mx = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        ll p = (a[i-1] - (n-i+1)*k), q = (2*i-n-1);
        if (q == 0) continue;
        if (p % q != 0) { cout << "NO\n"; return; }
        mn = min(mn, p/q), mx = max(mx, p/q);
    }
    // cout << mn << ' ' << mx << '\n';
    if ((mn == mx && mn >= 0 && mx <= k) || (mn == LLONG_MAX && mx == LLONG_MIN)) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
/*
    if we do operation 1 x times, 2 y times
    then element a[i] will be decrease by i*x + (n-i+1)*y
    that means a[i] = i*x + (n-i+1)*y
    k = n*(n+1)/2
    sum a = k*x + k*y
    x+y = sum a/k

    a[i] mod i = p
    
*/
