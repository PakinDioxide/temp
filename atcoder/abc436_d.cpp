#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair <int, int> d[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    string s[n];
    for (auto &e : s) cin >> e;
    int dis[n][n]; for (auto &E : dis) for (auto &e : E) e = INT_MAX;
    dis[0][0] = 0;
    map <char, vector <int, int>> mp;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] >= 'a' && a[i][j] <= 'z') mp[a[i][j]].emplace_back(i, j);
    pair <int, int> wp;

}

