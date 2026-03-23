#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 3005;

vector <string> a;
int X[mxN][mxN], Y[mxN][mxN], mk[mxN][mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    a.resize(n);
    for (auto &e : a) cin >> e;
    X[0][0] = (a[0][0] != '*');
    Y[n-1][m-1] = (a[n-1][m-1] != '*');
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (i > 0) X[i][j] = max(X[i][j], X[i-1][j]);
        if (j > 0) X[i][j] = max(X[i][j], X[i][j-1]);
        if (a[i][j] == '*') X[i][j] = 0;
    }
    for (int i = n-1; i >= 0; i--) for (int j = m-1; j >= 0; j--) {
        if (i < n-1) Y[i][j] = max(Y[i][j], Y[i+1][j]);
        if (j < m-1) Y[i][j] = max(Y[i][j], Y[i][j+1]);
        if (a[i][j] == '*') Y[i][j] = 0;
    }
    ll cnt = 0;
    for (auto &E : a) for (auto &e : E) cnt += e == '.';
    if (X[n-1][m-1] == 0) {
        cout << cnt * (cnt-1) / 2 << '\n';
        return 0;
    }
    deque <pair <int, int>> PE, PD;
    for (int i = n-1, j = m-1; ; ) {
        PE.emplace_front(i, j);
        if (i == 0 && j == 0) break;
        if (i > 0 && X[i-1][j]) i--;
        else j--;
    }
    for (int i = n-1, j = m-1; ; ) {
        PD.emplace_front(i, j);
        if (i == 0 && j == 0) break;
        if (j > 0 && X[i][j-1]) j--;
        else i--;
    }
    ll ans = 0, A = 0;
    for (int i = 0; i < n+m-1; i++) if (PD[i] == PE[i]) A++, mk[PD[i].first][PD[i].second] = 1;
    for (int k = 0; k < n+m-1; k++) {
        deque <pair <int, int>> P;
        if (mk[PD[k].first][PD[k].second]) continue;
        int xx = PD[k].first-1, yy = PD[k].second+1;
        while (!X[xx][yy] || !Y[xx][yy]) xx--, yy++;
        for (int i = xx, j = yy; ; ) {
            P.emplace_front(i, j);
            if (i == 0 && j == 0) break;
            if (j > 0 && X[i][j-1]) j--;
            else i--;
        }
        P.pop_back();
        for (int i = xx, j = yy; ; ) {
            P.emplace_back(i, j);
            if (i == n-1 && j == m-1) break;
            if (i < n-1 && Y[i+1][j]) i++;
            else j++;
        }
        assert(P.size() == PE.size());
        for (int i = 0; i < n+m-1; i++) if (P[i] == PE[i] && !mk[P[i].first][P[i].second]) ans++;
    }
    cout << ans + A * (cnt - A) + A * (A - 1) / 2 << '\n';
}

