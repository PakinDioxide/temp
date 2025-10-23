#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector <int> v;
    for (int i = 0; i < n; i++) if (s[i] == '1') v.emplace_back(i+1);
    if (v.size() == n) { cout << 0 << '\n'; return; }
    cout << v.size() << '\n';
    for (auto &e : v) cout << e << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    void solve();
}