/*
    author  : PakinDioxide
    created : 14/03/2025 03:18
    task    : 2019_Dec_B_3
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    map <string, int> mp;
    map <int, string> mp2;
    mp["Beatrice"] = 0;
    mp["Sue"] = 1;
    mp["Belinda"] = 2;
    mp["Bessie"] = 3;
    mp["Betsy"] = 4;
    mp["Blue"] = 5;
    mp["Bella"] = 6;
    mp["Buttercup"] = 7;
    mp2[0] = "Beatrice";
    mp2[1] = "Sue";
    mp2[2] = "Belinda";
    mp2[3] = "Bessie";
    mp2[4] = "Betsy";
    mp2[5] = "Blue";
    mp2[6] = "Bella";
    mp2[7] = "Buttercup";
    int n;
    cin >> n;
    vector <int> adj[8];
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a;
        for (int j = 0; j < 5; j++) cin >> b;
        adj[mp[a]].push_back(mp[b]);
        adj[mp[b]].push_back(mp[a]);
    }
    int vis[8];
    memset(vis, 0, sizeof(vis));
    vector <vector <string>> v;
    for (int i = 0; i < 8; i++) {
        if (vis[i]) continue;
        if (adj[i].size() > 1) continue;
        int cng = 1;
        vector <string> vv;
        vv.push_back(mp2[i]);
        vis[i] = 1;
        while (cng) {
            cng = 0;
            for (int V : adj[mp[vv.back()]]) {
                if (vis[V]) continue;
                vis[V] = 1;
                vv.push_back(mp2[V]);
                cng = 1;
                break;
            }
        }
        if (vv[0] > vv.back()) reverse(vv.begin(), vv.end());
        v.push_back(vv);
    }
    sort(v.begin(), v.end());
    for (auto e : v) for (auto ee : e) cout << ee << '\n';
}