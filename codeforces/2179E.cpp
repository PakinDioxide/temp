#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

void solve() {
    int n; ll x, y; cin >> n >> x >> y;
    string s; cin >> s; s = " " + s;
    ll p[n+1]; for (int i = 1; i <= n; i++) cin >> p[i];
    ll ss = 0;
    for (int i = 1; i <= n; i++) ss += p[i];
    if (ss > x+y) {
        cout << "NO\n";
        return;
    }
    ll a[n+1], b[n+1]; memset(a, 0, sizeof(a)), memset(b, 0, sizeof(b));
    int fa = 0, fb = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') a[i]++, x--, fa++;
        else b[i]++, y--, fb++;
        p[i]--;
    }
    if (x < 0 || y < 0 || (x > y && !fa) || (x < y && !fb)) { cout << "NO\n"; return; }
    int spa = 0, spb = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i] <= 0) continue;
        if (s[i] == '0') {
            int nd = p[i];
            if (nd <= x) x -= nd, spa += nd;
            else {
                spa += x;
                x = 0;
                if (nd <= spa) {
                    spa -= nd;
                    if (spb >= nd) spb -= nd;
                    else {
                        nd -= spb;
                        spb = 0;
                        if (y >= nd) y -= nd;
                        else { cout << "NO\n"; return; }
                    }
                } else { cout << "NO\n"; return; }
            }
        } else {
            int nd = p[i];
            if (nd <= y) y -= nd, spb += nd;
            else {
                spb += y;
                y = 0;
                if (nd <= spb) {
                    spb -= nd;
                    if (spa >= nd) spa -= nd;
                    else {
                        nd -= spa;
                        spa = 0;
                        if (x >= nd) x -= nd;
                        else { cout << "NO\n"; return; }
                    }
                } else { cout << "NO\n"; return; }
            }
        }
    }
    int mn = min(x, y);
    x -= mn, y -= mn;
    if ((x && !fa) || (y && !fb)) cout << "NO\n";
    else cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

