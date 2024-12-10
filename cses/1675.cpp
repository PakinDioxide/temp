#include <bits/stdc++.h>

using namespace std;

vector <int> par;

int f(int x) {
    if (par[x] != x) return par[x] = f(par[x]);
    return x;
}

int main() {
    int n, m;
    cin >> n >> m;

    priority_queue <pair <long long, pair <int, int>>> edge;

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if (a == b) continue;

        edge.push({-c, {a, b}});
    }


    for (int i = 0; i <= n; i++) par.push_back(i);

    long long ans = 0;

    while (!edge.empty()) {
        long long w = edge.top().first;
        int x = edge.top().second.first, y = edge.top().second.second;
        edge.pop();
        if (f(x) != f(y)) {
            par[f(y)] = f(x);
            ans -= w;
        }
    }

    int x = f(1);
    for (int i = 1; i <= n; i++) if (f(i) != x) {cout << "IMPOSSIBLE"; return 0;}
    cout << ans;
}
