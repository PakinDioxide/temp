#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<set<int>> r(n + 1), c(n + 1);

    for (int i = 0; i <= n; i++) {
        r[i].insert(1);
        r[i].insert(n);
        c[i].insert(1);
        c[i].insert(n);
    }

    for (int i = 0; i < m; i++) {
        char a;
        int b, j = 0;
        cin >> a >> b;

        int q = 0;

        if (a == 'N') {
            if (!r[b].empty() && *r[b].begin() == 1) {
                q = *next(r[b].begin()) - *r[b].begin() + 1;
                r[b].erase(r[b].begin());

                for (int p = 1; p <= n; p++) c[p].insert(b);
            }
        } else if (a == 'S') {
            j = r[b].size() - 1;
            if (!r[b].empty() && *r[b].rbegin() == n) {
                q = *r[b].rbegin() - *prev(r[b].rbegin()) + 1;
                r[b].erase(prev(r[b].end()));

                for (int p = 1; p <= n; p++) c[p].insert(b);
            }
        } else if (a == 'W') {
            if (!c[b].empty() && *c[b].begin() == 1) {
                q = *next(c[b].begin()) - *c[b].begin() + 1;
                c[b].erase(c[b].begin());

                for (int p = 1; p <= n; p++) r[p].insert(b);
            }
        } else if (a == 'E') {
            j = c[b].size() - 1;
            if (!c[b].empty() && *c[b].rbegin() == n) {
                q = *c[b].rbegin() - *prev(c[b].rbegin()) + 1;
                c[b].erase(prev(c[b].end()));

                for (int p = 1; p <= n; p++) r[p].insert(b);
            }
        }

        cout << q << "\n";
    }

    return 0;
}
