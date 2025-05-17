/*
    author  : PakinDioxide
    created : 08/05/2025 18:02
    task    : 510C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 105, mxK = 26;

int n, deg[mxK];
string a[mxN];
set <int> adj[mxK];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) for (int j = 0; j <= min(a[i].size(), a[i+1].size()); j++) {
        if (a[i].size() <= j) break;
        else if (a[i+1].size() <= j) { cout << "Impossible\n"; return 0; }
        if (a[i][j] != a[i+1][j]) { if ((adj[a[i][j]-'a'].emplace(a[i+1][j]-'a')).second) deg[a[i+1][j]-'a']++; break;}
    }
    vector <int> tp;
    queue <int> q;
    for (int i = 0; i < mxK; i++) if (!deg[i]) q.emplace(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        tp.emplace_back(u);
        for (auto v : adj[u]) if (!(--deg[v])) q.emplace(v);
    }
    if (tp.size() != mxK) cout << "Impossible";
    else for (auto &e : tp) cout << (char) (e + 'a');
    cout << '\n';
}