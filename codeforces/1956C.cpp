#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, cc = 0;
    cin >> n;
    int r[n], c[n], a[n][n], sum = n*(n+1)/2;
    memset(c, 0, sizeof(c));
    vector <pair <int, int>> op;
    for (int i = 0; i < n; i++) {
        r[i] = 0;
        for (int j = 0; j < n; j++) {
            r[i] += j+1;
            c[j] += j+1;
            a[i][j] = j+1;
        }
        cc++;
        op.emplace_back(1, i+1);
    }
    for (int j = 0; j < n; j++) {
        if (c[j] < sum && cc < 2*n) {
            cc++;
            c[j] = sum;
            for (int i = 0; i < n; i++) {
                r[i] = r[i] - a[i][j] + i+1;
                a[i][j] = i+1;
            }
            op.emplace_back(2, j+1);
        } else break;
    }
    for (int i = 0; i < n; i++) {
        if (r[i] < sum && cc < 2*n) {
            cc++;
            r[i] = sum;
            for (int j = 0; j < n; j++) {
                c[j] = c[j] - a[i][j] + i+1;
                a[i][j] = i+1;
            }
            op.emplace_back(1, i+1);
        } else break;
    }
    int sum2 = 0;
    for (int i = 0; i < n; i++) sum2 += r[i];
    cout << sum2 << ' ' << cc << '\n';
    for (auto [x, y] : op) {
        cout << x << ' ' << y;
        for (int i = 1; i <= n; i++) cout << ' ' << i;
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}