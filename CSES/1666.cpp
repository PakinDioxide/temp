#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> adj;
vector <bool> v;

void dfs(int n) {
    if (v[n]) return;

    v[n] = true;

    for (auto i : adj[n]) {
        dfs(i);
    }
}

int main() {
    int n, m;

    cin >> n >> m;

    adj.resize(n);
    v.resize(n);

    for (int i = 0; i < m; i++) {
        int a, b;

        cin >> a >> b;

        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector <int> none;

    for (int i = 0; i < n; i++) {
        if (!v[i]) {
            dfs(i);
            none.push_back(i+1);
        }
    }

    if (size(none) == 1) cout << 0;
    else {
        cout << size(none)-1 << "\n";

        for (int i = 1; i < size(none); i++) {
            cout << none[i-1] << " " << none[i] << "\n";
        }
    }
}
