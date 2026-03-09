#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll cnt(int x1, int y1, int x2, int y2) {
    if ((x1 + y1) % 2 == 0) {
        ll cx = x2-x1+1, cy = y2-y1+1;
        return ceil(cx/2.0)*ceil(cy/2.0) + (cx/2)*(cy/2);
    } else {
        ll cx = x2-x1+1, cy = y2-y1+1;
        return (cx/2)*ceil(cy/2.0) + ceil(cx/2.0)*(cy/2);
    }
}

struct orz {
    ll x1, y1, x2, y2;
};

orz itc(orz a, orz b) {
    if (a.x2 < b.x1 || b.x2 < a.x1 || a.y2 < b.y1 || b.y2 < a.y1) return {INT_MIN, 0, -1, -1};
    return {max(a.x1, b.x1), max(a.y1, b.y1), min(a.x2, b.x2), min(a.y2, b.y2)};
}

void solve() {
    ll n, m; cin >> n >> m;
    ll ans = cnt(1, 1, n, m);
    // cout << ans << ' ';
    orz a, b;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    ans += (a.x2 - a.x1 + 1) * (a.y2 - a.y1 + 1) - cnt(a.x1, a.y1, a.x2, a.y2);
    // cout << ans << ' ';
    ans -= cnt(b.x1, b.y1, b.x2, b.y2);
    // cout << ans << ' ';
    orz it = itc(a, b);
    // ans -= (it.x2 - it.x1 + 1) * (it.y2 - it.y1 + 1);
    if (it.x1 > INT_MIN) ans -= (it.x2 - it.x1 + 1) * (it.y2 - it.y1 + 1) - cnt(it.x1, it.y1, it.x2, it.y2); 
    cout << ans << ' ' << n*m - ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

