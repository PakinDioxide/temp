#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    map <pair <int, int>, int> mp, vis;
    int T[n]; for (auto &e : T) e = INT_MAX;
    int x = 0, y = 0;
    mp[{0, 0}] = 0, vis[{0, 0}] = 1;
    int it = 0;
    for (auto &e : s) {
        ++it;
        if (e == 'R') x++;
        else if (e == 'L') x--;
        else if (e == 'U') y++;
        else y--;
        if (vis[{x, y}]) T[it-1] = it - mp[{x, y}];
        vis[{x, y}] = 1;
        mp[{x, y}] = it;
    }
    for (int i = n-2; i >= 0; i--) T[i] = min(T[i], T[i+1]);
    int curr = 1;
    ll ans = 1;
    deque <pair <int, int>> V;
    V.emplace_back(0, 0);
    map <pair <int, int>, int> vv, vvv;
    vv[{0, 0}] = 1;
    // for (int i = 0; i < n; i++) cout << T[i] << ' '; cout << '\n';
    x = y = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') x++;
        else if (s[i] == 'L') x--;
        else if (s[i] == 'U') y++;
        else y--;
        if (curr < T[i] && !vv[{x, y}] && !vvv[{x, y}]) {
            curr++;
            // cout << "D " << i << '\n';
            vv.clear();
            vvv.clear();
            vvv[{x, y}] = 1;
            for (auto &[x, y] : V) vvv[{x, y}] = vv[{x, y}] = 1;
        } else {
            vv[{V[0].first, V[0].second}] = 0;
            V.pop_front();
        }
        V.emplace_back(x, y);
        vv[{x, y}] = 1;
        ans += curr;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

