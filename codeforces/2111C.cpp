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
    int n; cin >> n;
    ll a[n]; for (auto &e : a) cin >> e;
    ll dpl[n], dpr[n];
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] == a[i-1]) dpl[i] = dpl[i-1];
        else dpl[i] = a[i]*i;
    }
    for (int i = n-1; i >= 0; i--) {
        if (i < n-1 && a[i] == a[i+1]) dpr[i] = dpr[i+1];
        else dpr[i] = a[i]*(n-i-1);
    }
    ll mn = LLONG_MAX;
    for (int i = 0; i < n; i++) mn = min(mn, dpl[i] + dpr[i]);
    cout << mn << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

