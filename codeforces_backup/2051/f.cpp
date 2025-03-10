#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    // cout << "> ";
    ll n, m, q;
    cin >> n >> m >> q;
    ll l = m, r = m, nl = 0, nr = n+1, emp = 0;
    while (q--) {
        ll x;
        cin >> x;
        if (x > nl && nl > 0) nl++;
        if (x < nr && nr < n+1) nr--;
        if (x <= nl) nr = min(nr, n);
        if (x >= nr) nl = max(nl, 1LL);
        if (x < l && !emp) l--;
        else if (x > r && !emp) r++;
        else if (!emp) {
            nl = max(nl, 1LL), nr = min(nr, n);
            if (l == r) l++, emp = 1;
        }
        if (nl >= l && !emp) nl = 0, l = 1, emp = 0;
        if (r >= nr && !emp) nr = n+1, r = n, emp = 0;
        if (nl >= nr) nl = 0, nr = n+1, l = 1, r = n, emp = 0;
        cout << (r-l+1) + nl + (n+1-nr) << ' ';
        // cout << ' ' << l << ' ' << r << ' ' << nl << ' ' << nr << '\n';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
/*
18 15 4
13 15 1 16

XXOOOOOOOOOOXXXXXX

BEING
*/