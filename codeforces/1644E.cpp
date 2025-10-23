#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll calc(string s, ll n) {
    ll ans = 0, y = 0;
    int l;
    for (int i = 0; i < s.size(); i++) if (s[i] == 'R') { l = i; break; }
    ans = l * (n-1);
    for (int i = s.size()-1; i >= l; i--) {
        if (s[i] == 'D') ans += y;
        else y++;
    }
    return ans;
}

void solve() {
    ll n; cin >> n;
    string s; cin >> s;
    int r = 0, d = 0;
    for (auto &e : s) r += (e == 'R'), d += (e == 'D');
    if (r == 0 || d == 0) { cout << n << '\n'; return; }
    ll ans = n*n;
    ans -= calc(s, n);
    for (auto &e : s) e = (e == 'R' ? 'D' : 'R');
    ans -= calc(s, n);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}