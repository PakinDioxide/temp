#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int q; cin >> q;
    while (q--) {
        int t; ll x, y; cin >> t >> x >> y;
        if (t == 1) {
            if (x + x > y) { cout << x << '\n'; continue; }
            ll tt = x+x, pos = x-1;
            while (tt + pos + 1 <= y) {
                tt += pos + 1;
                // cout << tt-1 << '\n';
                pos = tt/2;
            }
            cout << pos - (y - tt) << '\n';
        } else {
            if (y == 0) { cout << 0 << '\n'; continue; }
            if (x + x > y) { cout << x << '\n'; continue; }
            y += x;
            while (1) {
                int k = y * 2 / 3;
                // cout << k << '\n';
                if (k + k/2 == y) y = k-1;
                else {
                    k++;
                    if (k + k/2 == y) y = k-1;
                    else {
                        k -= 2;
                        if (k + k/2 == y) y = k-2;
                        else { cout << fixed << setprecision(0) << ceil((long double) y/3.0) << '\n'; break; }
                    }
                }
                // cout << y << '\n';
                if (y == 0) { cout << 0 << '\n'; break; }
            }
            continue;
            vector <int> v; v.emplace_back(0);
            y += x;
            // find that which element at time y is at pos = 0
            int lst = y/3;
            y--;
            while (1) {
                int pos = y - lst;
            }
            continue;
            int c = 0;
            for (int i = 1; i <= y; i++) {
                c++;
                int k = v[0];
                v.erase(v.begin());
                v.insert(v.begin() + i/2, k);
                v.emplace_back(i);
                cout << v[0] << ' ';
                if (v[0] == 0) cout << " : " << c << '\n';
                continue;
                for (auto &e : v) cout << e << ' '; cout << '\n';
            }
        }
    }
}

// max jump <= 102
