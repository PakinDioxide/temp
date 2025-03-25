/*
    author  : PakinDioxide
    created : 25/03/2025 21:22
    task    : apocalypse
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <pair <int, double>> adj[n];
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            double x;
            cin >> x;
            adj[u].emplace_back(v, x);
        }
    }
    int idx = -1, mn = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        double dis[n];
        memset(dis, 0, sizeof(dis));
        dis[i] = 100;
        priority_queue <pair <double, int>> q;
        q.emplace(100, i);
        while (!q.empty()) {
            
        }
    }
}