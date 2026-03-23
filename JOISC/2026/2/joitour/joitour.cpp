#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

const int mxN = 2e5+5;

int n, a[mxN], b[mxN], q, m, cnt[mxN], curr[mxN], ans[mxN];
vector <int> adj[mxN];

int32_t main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    cin >> m;
    vector <tuple <int, int, int>> Q(m);
    int sqT = ceil(sqrt(n));
    for (auto &[idk, r, l] : Q) {
        cin >> l >> r;
        if (r < l) swap(l, r);
        idk = l / sqT;
    }
    sort(Q.begin(), Q.end());
    cin >> q;
    for (int i = 1; i <= q; i++) cin >> b[i];
    auto add = [&] (int x) {
        /*
        for (int i = 1; i <= q; i++) {
            if (b[i] - x > n || b[i] - x <= 0 || b[i] - x == x) continue;
            curr[i] += cnt[b[i] - x];
        }
        */
        cnt[x]++;
    };
    auto rm = [&] (int x) {
        /*
        for (int i = 1; i <= q; i++) {
            if (b[i] - x > n || b[i] - x <= 0 || b[i] - x == x) continue;
            curr[i] -= cnt[b[i] - x];
        }
        */
        cnt[x]--;
    };
    int L = 1, R = 0;
    for (auto &[idk, r, l] : Q) {
        while (R < r) add(a[++R]);
        while (L > l) add(a[--L]);
        while (R > r) rm(a[R--]);
        while (L < l) rm(a[L++]);
        /*
        for (int i = 1; i <= q; i++) {
            ans[i] += curr[i];
            if (b[i] % 2 == 0) ans[i] += cnt[b[i]/2] * (cnt[b[i]/2] - 1) / 2;
        }
        */
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}

