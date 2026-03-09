#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string s; cin >> s;
    int c = 0;
    for (auto &e : s) c += (e == 'Y');
    if (c <= 1) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

