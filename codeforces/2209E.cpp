#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    s = " " + s;
    while (q--) {
        int l, r;
        cin >> l >> r;
        ll ans = 0;
        int sz = 0;
        for (int i = l; i <= r; i++) {
            if (sz == 0 || s[((i-l) % sz) + l] != s[i]) sz = i-l+1;
            ans += ceil((double) (i-l+1) / sz);
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

