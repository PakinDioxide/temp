#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <tuple <int, int, int>> E, N;
    vector <tuple <char, int, int>> a(n);
    int id = -1;
    for (auto &[o, x, y] : a) {
        ++id;
        cin >> o >> x >> y;
        if (o == 'N') N.emplace_back(x, y, id);
        else E.emplace_back(x, y, id);
    }
    int ans[n][n]; id = -1;
    for (auto &[o, x, y] : a) {
        ++id;
        int mn = INT_MAX;
        if (o == 'N') {
            for (auto &[xx, yy, idx] : E) {
                if (x - xx < yy - y && x - xx > 0 && yy - y > 0) ans[id][idx] = yy - y;
                else ans[id][idx] = INT_MAX;
            }
            for (auto &[xx, yy, idx] : N) {
                if (x != xx || yy <= y) {ans[id][idx] = INT_MAX; continue;}
                ans[id][idx] = min(mn, yy-y);
            }
        } else {
            for (auto &[xx, yy, idx] : N) {
                if (xx - x > y - yy && xx - x > 0 && y - yy > 0) ans[id][idx] = xx - x;
                else ans[id][idx] = INT_MAX;
            }
            for (auto &[xx, yy, idx] : E) {
                if (y != yy || xx <= x) {ans[id][idx] = INT_MAX; continue;}
                ans[id][idx] = min(mn, xx-x);
            }
        }
    }
    // int mn[n];
    // for (int i = 0; i < n; i++) mn[i] = INT_MAX;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) mn[j] = min(mn[j], ans[i][j]);
    // }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) cout << (ans[i][j] == INT_MAX ? 0 : ans[i][j]) << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';
    for (int iter = 0; iter < n*n; iter++) {
        for (int i = 0; i < n; i++) {
            int m = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (ans[i][j] < m && ans[j][j] >= ans[i][j]) m = ans[i][j];
            }
            ans[i][i] = m;
            // mn[i] = INT_MAX;
            // for (int j = 0; j < n; j++) mn[i] = min(mn[i], ans[j][i]);
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) cout << (ans[i][j] == INT_MAX ? 0 : ans[i][j]) << ' ';
    //     cout << '\n';
    // }
    for (int i = 0; i < n; i++) {
        if (ans[i][i] == INT_MAX) cout << "Infinity\n";
        else cout << ans[i][i] << '\n';
    }
}