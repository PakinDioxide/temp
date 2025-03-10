#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    ll mx = 0;
    vector <ll> a(n);
    for (auto &e : a) cin >> e, mx += e;
    while (a.size() > 1) {
        ll sum = 0;
        for (int i = 0; i < n-1; i++) a[i] = a[i+1] - a[i], sum += a[i];
        a.pop_back();
        n--;
        mx = max(mx, abs(sum));
    }
    cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}