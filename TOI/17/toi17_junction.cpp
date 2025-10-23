#include <bits/stdc++.h>

using namespace std;

int n, ans = 0, l = 0, r = 1600000000;
vector <pair <int, int>> adj[100000];
vector <int> vv;

void dfs(int u, int p) {
    for (auto [v, w] : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        vv.push_back(w);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    for (int i = 0; i <= n; i++) {
        if (adj[i].size() == 1) {dfs(i, i); break;}
    }
    while (l <= r) {
        int mid = l + (r - l)/2, sum = 0, cnt = 0;
        for (int i : vv) {
            sum += i;
            if (sum >= mid) {sum = 0, cnt++;}
        }
        if (cnt >= 3) {l = mid+1; ans = mid;}
        else r = mid-1;
    }
    printf("%d", ans);
}