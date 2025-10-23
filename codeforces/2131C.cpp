/*
    author  : 
    created : 10/08/2025 21:43
    task    : 2131C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; ll k; cin >> n >> k;
    ll a[n], b[n]; for (auto &e : a) cin >> e; for (auto &e : b) cin >> e;
    map <ll, int> mp;
    for (auto &e : a) mp[e%k]++;
    for (auto &e : b) {
        e %= k;
        if (mp[e]) mp[e]--;
        else if (mp[k-e]) mp[k-e]--;
        else { cout << "NO\n"; return; }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}