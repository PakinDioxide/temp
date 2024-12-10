#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> adj;
vector <int> c;

void dfs(int n, int x) {

    c[n] = 1;

    for (auto i : adj[n]) {
        if (i == x) continue;

        dfs(i, n);
        c[n] += c[i];
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    c.resize(n);

    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;

        a--;

        adj[a].push_back(i);
    }

    dfs(0, 0);

    cout << c[0]-1;

    for (int i = 1; i < n; i++) {
        cout << " " << c[i]-1;
    }
}
