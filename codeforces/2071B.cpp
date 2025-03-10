#include <bits/stdc++.h>
#define ll long long

using namespace std;

int chk(ll x) {
    return (((ll) sqrt(x))*((ll) sqrt(x)) != x);
}

void solve() {
    ll n;
    cin >> n;
    if (!chk(n*(n+1)/2)) {cout << -1 << '\n'; return;}
    ll a[n], sum = 0, swp = 0;
    for (int i = 0; i < n; i++) {
        sum += i+1;
        a[i] = i+1;
        if (swp) swap(a[i], a[i-1]);
        swp = 0;
        if (!chk(sum)) swp = 1;
    }
    for (int i : a) cout << i << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}