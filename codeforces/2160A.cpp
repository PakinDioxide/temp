#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n; int a[n]; for (auto &e : a) cin >> e;
    vector <int> cnt(105);
    for (auto &e : a) cnt[e]++;
    for (int i = 0; i <= 100; i++) if (cnt[i] == 0) {cout << i << '\n'; return;}
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}