/*
    author  : PakinDioxide
    created : 26/05/2025 21:36
    task    : 2114B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    int zr = 0;
    string s; cin >> s;
    for (auto &e : s) zr += (e == '0');
    int cnt = 0, on = n-zr;
    if (zr < on) swap(zr, on);
    while (cnt < k) {
        if (zr < 2) break;
        zr -= 2; cnt++;
        if (zr < on) swap(zr, on);
    }
    if (cnt < k || abs(on-zr)/2 > 0) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}