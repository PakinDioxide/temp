#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, q;
map <pair <int, int>, int> mp, vis;

int get(int l, int r) {
    if (vis[{l, r}]) return mp[{l, r}];
    cout << "? " << l << ' ' << min(r, n) << endl;
    int x; cin >> x;
    vis[{l, r}] = 1;
    return mp[{l, r}] = min(r, n)-l+1 - x;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    vector <int> v;
    int sqT = ceil(sqrt(n));
    for (int i = 1; i < n; i += sqT) v.emplace_back(i);
    v.emplace_back(n);
    while (q--) {
        int k; cin >> k;
        int l = 0, r = v.size()-1;
        int R = 0;
        mp.clear(), vis.clear();
        while (l <= r) {
            int x = l + (r-l)/2;
            if (get(1, v[x]) < k) l = x+1;
            else R = v[x], r = x-1;
        }
        l = max(1, R - sqT), r = R;
        int ans = 0;
        if (l == r) { ans = l; goto orz; }
        while (l <= r) {
            int x = l + (r-l)/2;
            if (get(1, x) < k) l = x+1;
            else ans = x, r = x-1;
        }
        orz:
        cout << "! " << ans << endl;
    }
}

