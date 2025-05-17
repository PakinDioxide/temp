#include <bits/stdc++.h>
#define ll long long

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

const int mxN = 1005, mxM = 15;

int n, m, q, vis[mxN][mxM];
pair <int, char> adj[mxN][mxM];
unordered_map <char, int> mp;
string s, ans = "", ans2 = "";

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) { char x; cin >> x; mp[x] = i; }
    for (int i = 0; i < n*m; i++) {
        int u, v; char x, y;
        cin >> u >> x >> v >> y;
        adj[u][mp[x]] = make_pair(v, y);
    }
    cin >> s;
    int st = 0, idx = 0, it = 0;
    while (!vis[st][idx]) {
        vis[st][idx] = ++it;
        ans.push_back(adj[st][mp[s[idx]]].second);
        st = adj[st][mp[s[idx]]].first;
        idx = (idx + 1) % ((int) s.size());
    }
    int k = vis[st][idx]-1, sz = (int)(ans.size()) - k;
    for (int i = k; i < ans.size(); i++) ans2.push_back(ans[i]);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        while (l <= min(k-1, r)) cout << ans[l++];
        l -= k, r -= k;
        while (l <= r && (l % sz) != 0) cout << ans2[(l++)%sz];
        while (l + sz - 1 <= r) cout << ans2, l += sz;
        while (l <= r) cout << ans2[l%sz], l++;
        // while (l <= r) cout << ans[(l >= k ? k + (l-k) % ((int)(ans.size()) - k): l)], l++;
        cout << '\n';
    }
}
