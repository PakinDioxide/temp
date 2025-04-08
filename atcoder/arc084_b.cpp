/*
    author  : PakinDioxide
    created : 06/04/2025 19:51
    task    : arc084_b
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    ll dis[n];
    deque <pair <int, int>> q;
    for (int i = 0; i < n; i++) dis[i] = INT_MAX;
    dis[1] = 1;
    q.emplace_back(1, 1);
    while (!q.empty()) {
        auto [w, u] = q.front();
        q.pop_front();
        if (dis[u] != w) continue;
        if (u % 10 < 9) {
            int v = (u+1)%n;
            if (dis[v] > dis[u] + 1) q.emplace_back(dis[v] = dis[u] + 1, v);
        }
        int v = (10*u)%n;
        if (dis[v] > dis[u]) q.emplace_front(dis[v] = dis[u], v);
    }
    cout << dis[0] << '\n';
}