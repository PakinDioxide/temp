#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, t;
    scanf("%d %d %d", &n, &k, &t);
    vector <int> adj[n+1], ind(n+1), lc(k+1), lcc(k+1);
    int l[n+1];
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d %d", &l[i], &x);
        lc[l[i]]++;
        ind[i] = x;
        while (x--) {
            int v;
            scanf("%d", &v);
            adj[v].emplace_back(i);
        }
    }
    priority_queue <pair <int, int>> q;
    queue <int> ans;
    for (int i = 1; i <= n; i++) if (!ind[i]) q.emplace(-l[i], i);
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        ans.emplace(u);
        for (int v : adj[u]) {
            if (--ind[v] == 0) q.emplace(-l[v], v);
        }
    }
    if (ans.size() < t) {printf("-1"); return 0;}
    for (int i = 0; i < t; i++) {
        int u = ans.front();
        ans.pop();
        lcc[l[u]]++;
        printf(" U : %d\n", u);
    }
    int an = 0;
    for (int i = 1; i <= k; i++) {
        printf(" L : %d\n", lcc[i]);
        if (lcc[i] == lc[i]) an++;
        else break;
    }
    printf("%d", an);
}