#include <bits/stdc++.h>
#define ll long long
// #define int ll

using namespace std;

int mx = 0, bt;

void ss(int idx, int n, int k) {
    if (k == 0) return;
    if (idx < 0) {
        vector <int> v;
        for (int i = bt; i >= 0; i--) {
            if (!(n & (1 << i))) continue;
            else {
                if (n & (1 << (i+1))) v.back()++;
                else v.emplace_back(1);
            }
        }
        // for (auto &[x, y] : v) if (x != 0) cout << "(" << x << ' ' << y << ") "; cout << '\n';
        sort(v.begin(), v.end());
        int cc = 0;
        while (!v.empty() && k && v.back() > 1) cc += v.back(), v.pop_back(), k--;
        mx = max(mx, cc+k);
        return;
    }
    if (n & (1 << idx)) ss(idx-1, n, k);
    else {
        int c = 0, i;
        for (i = idx; ((n & (1 << i)) == 0) && i >= 0; i--) c++;
        if (k >= c) {
            int nn = n;
            for (int ii = idx; ii > i; ii--) nn |= (1 << ii);
            ss(i, nn, k-c);
        }
        // if (i >= 0 && !(n & (1 << i))) exit(1);
        ss(i, n, k);
    }
}

void solve() {
    int n, k; cin >> n >> k;
    mx = 0;
    
    bt = 29;
    while (!(n & (1 << bt))) bt--;
    int cnt = 0;
    for (int i = 0; i <= bt; i++) if ((n & (1 << i)) == 0) cnt++;
    if (cnt < k) {
        cout << (bt+1-cnt) + (k-1) << '\n';
        return;
    }
    // for (int i = 29; i >= 0; i--) cout << ((n & (1 << i)) != 0); cout << '\n';

    ss(bt, n, k);
    cout << mx << '\n';
    
    
    // int ans = 0;
    // while (k) {
    //     int c = 0;
    //     for (int i = 0; i < 60; i++) if (n & (1 << i)) c++;
    //     if (c == 1) break;
    //     vector <pair <int, int>> v;
    //     v.emplace_back(0, 60);
    //     for (int i = 60; i >= 0; i--) {
    //         if (!(n & (1 << i))) v.emplace_back(0, i);
    //         else {
    //             if (n & (1 << (i+1))) v.back().first++;
    //             else v.emplace_back(1, i);
    //         }
    //     }
    //     // for (auto &[x, y] : v) if (x != 0) cout << "(" << x << ' ' << y << ") "; cout << '\n';
    //     sort(v.begin(), v.end());
    //     reverse(v.begin(), v.end());
    //     auto [y, x] = v[0];
    //     // cout << y << ' ' << x << '\n';
    //     ans += y;
    //     for (int i = x; (n & (1 << i)); i--) n ^= (1 << i);
    //     n |= (1 << (x+1));
    //     k--;
    // }
    // ans += k;
    // cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

/*

01010101 
01010110 1
01011000 2
01100000 2
10000000 2

010001
011000 3



3 6
8 5

30 c 15 = TLE..

*/