#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    for (auto &e : s) e -= '0';
    int c = 0;
    vector <int> v;
    for (int i = 0; i < n; i++) {
        if (s[i] == 0) c++;
        else if (s[i] == 1 && c > 0) v.emplace_back(c), c = 0;
    }
    if (c > 0) v.emplace_back(c);
    int mx = 0;
    for (auto &e : v) mx = max(mx, e);
    if (s[0] == 0 && s[n-1] == 0) mx = max(mx, v[0] + v.back());
    cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}