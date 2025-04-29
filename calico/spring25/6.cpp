/*
    author  : PakinDioxide
    created : 27/04/2025 06:31
    task    : 6
*/
#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

string s;
int sz, n, m;
map <char, pair <int, int>> mp;
pair <int, int> p[10005];

int bs(int x, int y, int idx, int K) {
    int k = K;
    int g = k/sz;
    k %= sz;
    int dx = p[sz].first, dy = p[sz].second;
    dx *= g, dy *= g;
    if (k + idx - 1 <= sz) dx += p[k+idx-1].first - p[idx-1].first, dy += p[k+idx-1].second - p[idx-1].second;
    else dx += p[sz].first - p[idx-1].first + p[k+idx-1-sz].first, dy += p[sz].second - p[idx-1].second + p[k+idx-1-sz].second;
    dx %= n, dy %= m;
    // if (K <= 4) cout << "K " << K << ' ' << dx << ' ' << dy << '\n';
    int tx = min(n-abs(x-dx), abs(x-dx)), ty = min(m-abs(y-dy), abs(y-dy));
    return (tx + ty <= K);
}

int bbs(int x, int y, int idx) {
    idx = (idx-1)%sz+1;
    int l = 0, r = 1e8, ans = INT_MAX;
    while (l <= r) {
        int m = l + (r-l)/2;
        if (bs(x, y, idx, m)) ans = m, r = m-1;
        else l = m+1;
    }
    // cout << "A " << ans << ' ' << x << ' ' << y << '\n';
    return ans;
}

void solve() {
    cin >> n >> m;
    cin >> s;
    int a[n][m], ans = 0;
    sz = s.size();
    s = ' ' + s;
    p[0] = {0, 0};
    for (int i = 1; i <= sz; i++) p[i] = make_pair(p[i-1].first + mp[s[i]].first, p[i-1].second + mp[s[i]].second);
    // cout << "P " << p[sz].first << ' ' << p[sz].second << '\n';
    vector <tuple <int, int, int>> v;
    v.emplace_back(0, 0, 0);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j], v.emplace_back(a[i][j], i, j);
    sort(v.begin(), v.end());
    auto up = [&] (int x, int y, int k) {
        if (y <= x) return y-x;
        else return -(x+k-y);
    };
    auto down = [&] (int x, int y, int k) {
        if (x <= y) return y-x;
        else return k-x+y;
    };
    for (int i = 0; i < n*m; i++) {
        int k, sx, sy, ex, ey;
        tie(k, sx, sy) = v[i];
        tie(k, ex, ey) = v[i+1];
        int mn = INT_MAX;
        mn = min(mn, bbs(up(sx, ex, n), up(sy, ey, m), ans+1)); // up up
        mn = min(mn, bbs(up(sx, ex, n), down(sy, ey, m), ans+1)); // up down
        mn = min(mn, bbs(down(sx, ex, n), up(sy, ey, m), ans+1)); // down up
        mn = min(mn, bbs(down(sx, ex, n), down(sy, ey, m), ans+1)); // down down
        // cout << sx << ' '<< sy << ' ' << ex << ' ' << ey << ' ' << mn << '\n';
        // cout << "-------\n";
        ans += mn;
    }
    cout << ans << '\n';
}

int32_t main() {
    mp['U'] = {-1, 0};
    mp['D'] = {1, 0};
    mp['L'] = {0, -1};
    mp['R'] = {0, 1};
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}