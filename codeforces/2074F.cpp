/*
    author  : PakinDioxide
    created : 11/03/2025 22:53
    task    : 2074F
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

map <tuple <ll, ll, ll>, ll> dp, vis;

ll dvc(ll h, ll l, ll b) {
    if (vis[{h, l, b}]) return dp[{h, l, b}];
    vis[{h, l, b}] = 1;
    if (b == 1) return dp[{h, l, b}] = 1LL;
    if (h == l && h == b) return dp[{h, l, b}] = 1LL;
    ll ans = 0;
    if (h > b/2) {
        ans += dvc(h-b/2, min(l, b/2), b/2);
        if (l > b/2) ans += dvc(h-b/2, l-b/2, b/2);
    }
    ans += dvc(min(h, b/2), min(l, b/2), b/2);
    if (l > b/2) ans += dvc(min(h, b/2), l-b/2, b/2);
    return dp[{h, l, b}] = ans;
}

ll slce(ll a[4], ll b[4]) {
    if ((a[0] == b[0] && (a[1] == b[1] || a[3] == b[3])) || (a[2] == b[2] && (a[1] == b[1] || a[3] == b[3]))) return dvc(abs(a[0] - a[2]), abs(a[1] - a[3]), abs(b[0] - b[2]));
    ll mx = (b[0] + b[2])/2, my = (b[1] + b[3])/2;
    ll ans = 0, aa[4], bb[4];
    if (a[2] > mx) {
        if (a[3] > my) {
            aa[2] = a[2];
            aa[3] = a[3];
            aa[0] = max(mx, a[0]);
            aa[1] = max(my, a[1]);
            bb[2] = b[2];
            bb[3] = b[3];
            bb[0] = mx;
            bb[1] = my;
            ans += slce(aa, bb);
        }
        if (a[1] < my) {
            aa[2] = a[2];
            aa[1] = a[1];
            aa[0] = max(mx, a[0]);
            aa[3] = min(my, a[3]);
            bb[2] = b[2];
            bb[1] = b[1];
            bb[0] = mx;
            bb[3] = my;
            ans += slce(aa, bb);
        }
    }
    if (a[0] < mx) {
        if (a[3] > my) {
            aa[0] = a[0];
            aa[3] = a[3];
            aa[2] = min(mx, a[2]);
            aa[1] = max(my, a[1]);
            bb[0] = b[0];
            bb[3] = b[3];
            bb[2] = mx;
            bb[1] = my;
            ans += slce(aa, bb);
        }
        if (a[1] < my) {
            aa[0] = a[0];
            aa[1] = a[1];
            aa[2] = min(mx, a[2]);
            aa[3] = min(my, a[3]);
            bb[0] = b[0];
            bb[1] = b[1];
            bb[2] = mx;
            bb[3] = my;
            ans += slce(aa, bb);
        }
    }
    return ans;
}

void solve() {
    ll a[4], b[4], mx = 0;
    for (int i = 0; i < 4; i++) cin >> a[i], mx = max(mx, a[i]);
    swap(a[1], a[2]);
    ll big = 1;
    while (big < mx) big *= 2;
    b[0] = b[1] = 0, b[2] = b[3] = big;
    // cerr << big << '\n';
    cout << slce(a, b) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}