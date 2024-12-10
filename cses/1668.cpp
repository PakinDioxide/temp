#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> adj;
vector <int> team;

bool dfs(int n) {
    int nex = team[n] == 1 ? 2 : 1;

    for (auto i : adj[n]) {
        if (team[i] != 0) {
            if (team[i] != nex) return false;
        }
        else {
            team[i] = nex;

            if (!dfs(i)) return false;
        }
    }

    return true;
}

int main() {
    int n, m;

    cin >> n >> m;

    adj.resize(n);
    team.resize(n);

    for (int i = 0; i < m; i++) {
        int a, b;

        cin >> a >> b;

        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (team[i] == 0) {
            team[i] = 1;
            if (!dfs(i)) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }

    cout << team[0];
    for (int i = 1; i < n; i++) cout << " " << team[i];
}
