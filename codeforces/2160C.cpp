#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll x; cin >> x;
    vector <int> k;
    while (x > 0 && x % 2 == 0) x/=2;
    while (x > 0) k.emplace_back(x % 2), x /= 2;
    if ((int) (k.size()) % 2 == 1 && k[k.size()/2] == 1) {cout << "NO\n"; return;}
    vector <int> xx; for (auto &e : k) xx.emplace_back(e); reverse(k.begin(), k.end());
    if (k == xx) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}