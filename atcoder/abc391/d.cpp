#include <bits/stdc++.h>
#define ll long long

using namespace std;

int32_t main() {
    int n, w;
    cin >> n >> w;
    vector <pair <int, int>> a[w+5];
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[x].emplace_back(y, i+1);
    }
    int h[n+5], dl[n+5], cng = 0, mxh = 0;
    map <int, int> c, cc;
    for (int i = 1; i <= w; i++) {
        sort(a[i].begin(), a[i].end());
        int cnt = 1;
        for (auto [x, idx] : a[i]) {
            h[idx] = cnt;
            cng += (cnt == 1);
            dl[idx] = x;
            c[cnt] = max(dl[idx], c[cnt]);
            cc[cnt]++;
            mxh = max(mxh, cnt);
            cnt++;
        }
    }
    vector <int> v;
    v.emplace_back(0);
    for (int i = 1; i <= mxh; i++) {
        if (cc[i] < w) break;
        // v.emplace_back(max(v[i-1]+1, c[i] + (i == 1)));
        v.emplace_back(c[i]);
        // cout << "H " << i << ' ' << v[i] << '\n';
    }
    int q;
    cin >> q;
    while (q--) {
        int t, idx;
        cin >> t >> idx;
        t = upper_bound(v.begin(), v.end(), t) - v.begin() - 1;
        if (h[idx] > t) cout << "Yes\n";
        else cout << "No\n";
        // cout << idx << ' ' << h[idx] << '\n';
    }
}