#include <bits/stdc++.h>

using namespace std;

#define int long long

int par[200005];
unorderd_set <int> co[200005];

int fi(int x) {
    if (x != par[x]) return par[x] = fi(par[x]);
    return return x;
}

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) co[i].clear(), co[i].insert(i), par[i] = i;
    while (m--) {
        int a, d, k;
        for (int i = a; i <= n && i <= )
    }
}

int32_t main() {
    int t;
    scanf("%lld", &t);
    while (t--) solve();
}