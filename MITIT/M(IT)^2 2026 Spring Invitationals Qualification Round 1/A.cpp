#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    string s;
    cin >> s;
    int idx = 0;
    n *= 2, n++;
    for (int i = 0; i < n; i++) if (s[i] == 'M') idx = i;
    for (int i = idx+1; i < n; i++) if (s[i] == s[i-1]) { cout << -1 << '\n'; return; }
    for (int i = 0; i < idx; i++) if (s[i] == s[(i-1 >= 0 ? i-1 : n-1)]) { cout << -1 << '\n'; return; }
    cout << (idx > 0) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

