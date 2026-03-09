#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string k = "";
    for (int i = 0; i < 3; i++) k += s[i];
    int s6 = 0, s5 = 0;
    for (int i = 3; i < n; i++) {
        k += s[i];
        if (k.size() > 4) k.erase(k.begin());
        if (k == "2025") s5++;
        if (k == "2026") s6++;
    }
    if (s6 || !s5) { cout << 0 << '\n'; return; }
    else cout << 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

