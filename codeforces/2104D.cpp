/*
    author  : PakinDioxide
    created : 28/04/2025 21:56
    task    : 2104D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <ll> prm;

bool is_prime(ll x) {
    if (x <= 1) return 0;
    if (x == 2) return 1;
    for (auto &e : prm) {
        if (e*e > x) break;
        if (x % e == 0) return 0;
    }
    return 1;
}

void solve() {
    int n;
    cin >> n;
    ll a[n];
    for (auto &e : a) cin >> e;
    sort(a, a+n);
    ll c = 0, ans = 0, idx = 0;
    for (int i = n-1; i >= 0; i--) {
        if (prm[idx] <= a[i]) c += a[i] - prm[idx], idx++;
        else if (prm[idx] <= a[i] + c) c -= prm[idx] - a[i], idx++;
        else ans++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 1; prm.size() < 4*100000+5; i++) if (is_prime(i)) prm.emplace_back(i);
    int t;
    cin >> t;
    while (t--) solve();
}