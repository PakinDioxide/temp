/*
    author  : PakinDioxide
    created : 17/04/2025 18:42
    task    : 1160
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, q, par[mxN], vis[mxN], dep[mxN], id[mxN], cyc[mxN], onst[mxN], cyccnt[mxN], idx = 0, dp[20][mxN];

int solve() {
    int x, y;
    cin >> x >> y;
    if (cyc[x] != cyc[y] || dep[y] > dep[x]) return -1;
    int k = dep[x] - dep[y];
    for (int i = 0; i < 20; i++) if (k & (1 << i)) x = dp[i][x];
    if (dep[x] != 0 && x != y) return -1;
    return k + (id[x] - id[y] < 0 ? id[x] - id[y] + cyccnt[cyc[x]] : id[x] - id[y]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> par[i];
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        int k = i;
        stack <int> st;
        while (!vis[k]) vis[k] = 1, st.emplace(k), onst[k] = 1, k = par[k];
        int cnt = 0;
        if (!cyc[k]) {++idx; while (st.top() != k) cyccnt[idx]++, id[st.top()] = ++cnt, cyc[st.top()] = idx, st.pop(); cyccnt[idx]++, id[st.top()] = ++cnt, cyc[st.top()] = idx, st.pop();}
        while (!st.empty()) id[st.top()] = -1, dep[st.top()] = dep[k] + 1, cyc[st.top()] = cyc[k], k = st.top(), st.pop();
    }
    for (int i = 1; i <= n; i++) dp[0][i] = par[i];
    for (int i = 1; i < 20; i++) for (int j = 1; j <= n; j++) dp[i][j] = dp[i-1][dp[i-1][j]];
    while (q--) cout << solve() << '\n';
}

/*
it will always lead to a cycle

first, we check if it is in the same connected componet

then we check the depth

we binary jump dep[a] - dep[b] times

if dep[a] != 0 and a != b return -1

else, we are in the cycle now

we mark the id in each cycle
*/