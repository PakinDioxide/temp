/*
    author  : PakinDioxide
    created : 16/03/2025 18:46
    task    : D2_A
*/
#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k, s, t;
    cin >> n >> m >> k >> s >> t;
    k++;
    vector <tuple <int, ll, int>> adj[n+1];
    ll p[k], sell[n+1][k];
    for (int i = 0; i < m; i++) {
        int u, v, c; ll w;
        cin >> u >> v >> w >> c;
        adj[u].emplace_back(v, w, c);
        // adj[v].emplace_back(u, w, c);
    }
    for (int i = 1; i < k; i++) cin >> p[i];
    memset(sell, 0, sizeof(sell));
    for (int i = 1; i < k; i++) {
        int cnt, x;
        cin >> cnt;
        for (int j = 0; j < cnt; j++) cin >> x, sell[x][i] = 1;
    }
    ll dis[n+1][(1 << k)], vis[n+1][(1 << k)], cnt1[n+1][(1 << k)];
    tuple <ll, ll, ll> par1[n+1][(1 << k)];
    for (int i = 0; i <= n; i++) for (int j = 0; j < (1 << k); j++) dis[i][j] = LLONG_MAX, vis[i][j] = 0, par1[i][j] = {-1, -1, -1}, cnt1[i][j] = 0;
    dis[s][0] = 0;
    priority_queue <tuple <ll, int , int, int>> q;
    q.emplace(0, s, 0, -1);
    while (!q.empty()) {
        int u = get<1>(q.top()), pass = get<2>(q.top()), par = get<3>(q.top());
        q.pop();
        if (vis[u][pass]) continue;
        vis[u][pass] = 1;
        // if (u == t || 1) cout << "FORW : " << u << ' ' << par << ' ' << pass << ' ' << dis[u][pass] << '\n';
        // no buy pass
        for (auto[v, w, c] : adj[u]) {
            if (dis[v][pass] > dis[u][pass] + ((pass & (1 << c)) ? 0 : w)) {
                dis[v][pass] = dis[u][pass] + ((pass & (1 << c)) ? 0 : w);
                cnt1[v][pass] = cnt1[u][pass]+1;
                par1[v][pass] = {u, pass, c};
                q.emplace(-dis[v][pass], v, pass, u);
            } else if (dis[v][pass] == dis[u][pass] + ((pass & (1 << c)) ? 0 : w) && cnt1[v][pass] > cnt1[u][pass] + 1) {
                cnt1[v][pass] = cnt1[u][pass] + 1;
                par1[v][pass] = {u, pass, c};
            }
        }
        // buy pass
        for (int i = 1; i < k; i++) {
            if (!sell[u][i] || (pass & (1 << i))) continue;
            int p2 = pass | (1 << i);
            if (dis[u][p2] > dis[u][pass] + p[i]) {
                dis[u][p2] = dis[u][pass] + p[i];
                cnt1[u][p2] = cnt1[u][pass]+1;
                par1[u][p2] = {u, pass, i};
                q.emplace(-dis[u][p2], u, p2, u);
            } else if (dis[u][p2] == dis[u][pass] + p[i] && cnt1[u][p2] > cnt1[u][pass] + 1) {
                cnt1[u][p2] = cnt1[u][pass] + 1;
                par1[u][p2] = {u, pass, i};
            }
            // for (auto [v, w, c] : adj[u]) {
            //     if (dis[v][p2] > dis[u][pass] + ((p2 & (1 << c)) ? 0 : w) + p[i]) {
            //         dis[v][p2] = dis[u][pass] + ((p2 & (1 << c)) ? 0 : w) + p[i];
            //         q.emplace(-dis[v][p2], v, p2);
            //     }
            // }
        }
    }

    // go back
    ll dis2[n+1][(1 << k)], vis2[n+1][(1 << k)], cnt2[n+1][(1 << k)];
    tuple <ll, ll, ll> par2[n+1][(1 << k)];
    for (int i = 0; i <= n; i++) for (int j = 0; j < (1 << k); j++) dis2[i][j] = LLONG_MAX, vis2[i][j] = 0;
    for (int j = 0; j < (1 << k); j++) if (dis[t][j] != LLONG_MAX) dis2[t][j] = dis[t][j], q.emplace(-dis2[t][j], t, j, -1), cnt2[t][j] = cnt1[t][j], par2[t][j] = par1[t][j];
    while (!q.empty()) {
        int u = get<1>(q.top()), pass = get<2>(q.top()), par = get<3>(q.top());
        q.pop();
        if (vis2[u][pass]) continue;
        vis2[u][pass] = 1;
        // if (u == s) cout << "BACK : " << u << ' ' << par << ' ' << pass << ' ' << dis[u][pass] << '\n';
        // no buy pass
        for (auto [v, w, c] : adj[u]) {
            if (dis2[v][pass] > dis2[u][pass] + ((pass & (1 << c)) ? 0 : w)) {
                dis2[v][pass] = dis2[u][pass] + ((pass & (1 << c)) ? 0 : w);
                cnt2[v][pass] = cnt2[u][pass]+1;
                par2[v][pass] = {u, pass, c};
                q.emplace(-dis2[v][pass], v, pass, u);
            } else if (dis[v][pass] == dis[u][pass] + ((pass & (1 << c)) ? 0 : w) && cnt2[v][pass] > cnt2[u][pass] + 1) {
                cnt2[v][pass] = cnt2[u][pass] + 1;
                par2[v][pass] = {u, pass, c};
            }
        }
        // buy pass
        for (int i = 1; i < k; i++) {
            if (!sell[u][i] || (pass & (1 << i))) continue;
            int p2 = pass | (1 << i);
            if (dis2[u][p2] > dis2[u][pass] + p[i]) {
                dis2[u][p2] = dis2[u][pass] + p[i];
                cnt2[u][p2] = cnt2[u][pass]+1;
                par2[u][p2] = {u, pass, i};
                q.emplace(-dis2[u][p2], u, p2, u);
            } else if (dis[u][p2] == dis[u][pass] + p[i] && cnt2[u][p2] > cnt2[u][pass] + 1) {
                cnt2[u][p2] = cnt2[u][pass] + 1;
                par2[u][p2] = {u, pass, i};
            }
            // if (!sell[u][i] || (pass & (1 << i))) continue;
            // int p2 = pass | (1 << i);
            // for (auto[v, w, c] : adj[u]) {
            //     if (dis2[v][p2] > dis2[u][pass] + ((p2 & (1 << c)) ? 0 : w) + p[i]) {
            //         dis2[v][p2] = dis2[u][pass] + ((p2 & (1 << c)) ? 0 : w) + p[i];
            //         q.emplace(-dis2[v][p2], v, p2);
            //     }
            // }
        }
    }
    ll ans = LLONG_MAX, idx = 0, cnt = 0, ccnt2 = LLONG_MAX;
    for (int j = 0; j < (1 << k); j++) {
        int ccnt = 0;
        for (int i = 0; i < k; i++) ccnt += ((j & (1 << i)) > 0);
        if (ans > dis2[s][j]) {
            ans = dis2[s][j];
            idx = j;
            cnt = ccnt;
            ccnt2 = cnt2[s][j];
        } else if (ans == dis2[s][j]) {
            if (cnt < ccnt) {
                idx = j;
                cnt = ccnt;
                ccnt2 = cnt2[s][j];
            } else if (cnt == ccnt) {
                if (ccnt2 > cnt2[s][j]) {
                    idx = j;
                    ccnt2 = cnt2[s][j];
                }
            }
        }
        // ans = min(ans, dis2[s][j]);//
        // cout << j << ' ' << dis2[s][j] << ' ' << ccnt << '\n';
    }
    cout << ans << '\n';
    stack <tuple <char, int, int, int>> st;
    int v = s, u, pass = idx;
    while (v != t) {
        u = get<0>(par2[v][idx]);
        int col = get<2>(par2[v][idx]);
        idx = get<1>(par2[v][idx]);
        if (u == v) {
            st.emplace('b', u, col, -1);
        } else st.emplace('a', u, v, col);
        v = u;
    }
    while (1) {
        u = get<0>(par1[v][idx]);
        if (u == -1) break;
        int col = get<2>(par1[v][idx]);
        idx = get<1>(par1[v][idx]);
        if (u == v) {
            st.emplace('b', u, col, -1);
        } else st.emplace('a', u, v, col);
        v = u;
    }
    cout << st.size() << '\n';
    while (!st.empty()) {
        auto [aa, aaa, aaaa, aaaaa] = st.top();
        st.pop();
        if (aa == 'a') cout << aa << ' ' << aaa << ' ' << aaaa << ' ' << aaaaa << '\n';
        else cout << aa << ' ' << aaa << ' ' << aaaa << '\n';
    }
}

/*
can we do the dijkstra from s -> t first
then push the dist to the array
then dijkstra back from t -> s
*/