#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second

using namespace std;

void solve() {
    int n; cin >> n;
    pair <ll, ll> a[n];
    for (auto &[x, y] : a) cin >> x >> y, x *= 2, y *= 2;
    ll L = 0, R = 1e9, ans = -1;
    while (L <= R) {
        ll k = L + (R-L)/2;
        vector <pair <pair <ll, ll>, pair <ll, ll>>> v, vv;
        for (auto [x, y] : a) v.emplace_back(make_pair(x-k, y-k), make_pair(x+k, y+k));
        sort(v.begin(), v.end());
        ll r = LLONG_MIN;
        for (auto &[p, q] : v) {
            auto [x1, y1] = p;
            auto [x2, y2] = q;
            // if (k == 4) cout << "E " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
            if (x1 > r) vv.emplace_back(make_pair(x1, y1), make_pair(x2, y2)), r = x2;
            else {
                if (!(vv.back().s.s < y1 || y2 < vv.back().f.s)) vv.back() = make_pair(make_pair(x1, max(vv.back().f.s, y1)), make_pair(x1, min(vv.back().s.s, y2)));
                else vv.emplace_back(make_pair(x1, y1), make_pair(x2, y2)), r = x2;
            }
        }
        int sz = vv.size(), ok = 1;
        // cout << k << ' ' << sz << '\n';
        vector <pair <ll, ll>> XX; XX.emplace_back(LLONG_MIN, LLONG_MIN);
        for (auto [p, q] : v) {
            auto [x1, y1] = p;
            auto [x2, y2] = q;
            auto it = prev(upper_bound(XX.begin(), XX.end(), make_pair(x1, LLONG_MAX)));

            // if (k == 4) cout << "IT : " << (*it).second << '\n';
            // if (k == 4) cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
            if (y2 < (*it).second) { ok = 0; break; }
            // if (x1 > X && y2 < Y) { ok = 0; break; }
            // if (y2 < y) continue;
            // if ()

            // X = min(X, x2), Y = max(Y, y1);
            // if (y1 > XX.back().second) XX.emplace_back(x2, y1);
            XX.emplace_back(x2+1, max(y1, XX.back().second));
            // ll p = vv[i].f.s, q = vv[i].s.s, r = vv[i].f.f, s = vv[i].s.f;
            // if (q < y && r < x) { ok = 0; break; }
            // else if (x <= r && y <= q) x = r, y = q;
            // else if (x <= r) 
        }
        if (ok) ans = k, R = k-1;
        else L = k+1;
        // break;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

/*
we find optimal x, optimal y

and find min, oh we cant
*/