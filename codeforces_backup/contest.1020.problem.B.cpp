#include <bits/stdc++.h>

using namespace std;

vector <int> adj;
vector <bool> v, t;

int dfs(int n) {
    if (v[n]) return n;

    v[n] = true;

    return dfs(adj[n]);
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    v.resize(n);
    t.resize(n);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        adj[i] = a-1;
    }

    for (int i = 0; i < n; i++) {
        v = t;
        cout << dfs(i)+1;
        if (i < n-1) cout << " ";
    }
}
