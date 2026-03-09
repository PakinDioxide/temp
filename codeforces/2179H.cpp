#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

ll cnt[mxN][20], cc[mxN][20], ans[mxN];

void solve() {
    int n, q; cin >> n >> q;    
    for (int i = 1; i <= n; i++) ans[i] = 0, memset(cnt[i], 0, sizeof(cnt[i]));
    vector <int> v[20];
    for (int ii = 1; ii <= n; ii++) {
        int cnt = 0, i = ii;
        while (!(i & 1)) cnt++, i = (i >> 1);
        v[cnt].emplace_back(ii);
    }
    for (int i = 0; i < 20; i++) {
        // cout << i << " : ";
        // for (auto &e : v[i]) cout << e << ' ';
        // cout << '\n';
    }
    while (q--) {
        int l, r; cin >> l >> r;
        for (int i = 0; i < 20; i++) {
            auto itl = lower_bound(v[i].begin(), v[i].end(), 1);
            if (itl == v[i].end()) continue;
            auto itr = upper_bound(v[i].begin(), v[i].end(), r-l+1);
            if (itr == v[i].begin()) continue;
            itr = prev(itr);
            int il = itl - v[i].begin();
            int ir = itr - v[i].begin();
            if (il > ir) continue;
            // cout << i << " : " << il << ' ' << ir << '\n';
            cnt[i][il+l-1]++;
            cnt[i][ir+1+l-1]--;
            cc[i][il+l-1] += il + l-1;
            cc[i][ir+1+l-1] -= il + l-1;
        }
    }
    for (int i = 0; i < 20; i++) for (int ii = 1; ii <= n; ii++) cnt[i][ii] += cnt[i][ii-1];
    for (int i = 0; i < 20; i++) {
        ll t = (1 << i), curr = 0, cur = 0;
        for (int ii = 1; ii <= n; ii++) {
            curr += cnt[i][ii];
            cur += cc[i][ii];
            ans[ii] += t * curr;
            continue;
            ans[ii] += t * (curr * ii - cur);
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

/*

*/
