/*
    author  : PakinDioxide
    created : 25/03/2025 03:23
    task    : arc084_b
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int dis[n];
    for (int i = 0; i < n; i++) dis[i] = INT_MAX;
    dis[1] = 1;
    queue <pair <int, int>> q;
    q.emplace(1, 1);
    while (!q.empty()) {
        auto [w, u] = q.front();
        q.pop();
        if (dis[u] != w) continue;
        int k = (10*u)%n;
        if (dis[k] > w) q.emplace(dis[k] = w, k);
        k = (u+1)%n;
        if (dis[k] > w+1) q.emplace(dis[k] = w+1, k);
    }
    cout << dis[0] << '\n';
}