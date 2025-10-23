/*
    author  : 
    created : 17/06/2025 21:55
    task    : 2121D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    vector <vector <int>> a(2, vector <int>(n));
    for (auto &e : a[0]) cin >> e;
    for (auto &e : a[1]) cin >> e;
    vector <pair <int, int>> ans;
    auto swp = [&] (int k, int i) {
        swap(a[k][i], a[k][i+1]);
        ans.emplace_back(k, i);
    };
    vector <int> p, q;
    for (int i = 0; i < n; i++) if (a[0][i] > n) p.emplace_back(i);
    for (int i = 0; i < n; i++) if (a[1][i] <= n) q.emplace_back(i);
    for (int i = 0; i < p.size(); i++) {
        int x = p[i], y = q[i];
        while (x > y) swp(0, --x);
        while (y > x) swp(1, --y);
        ans.emplace_back(2, x), swap(a[0][x], a[1][x]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i-1; j >= 0; j--) {
            if (a[0][j] > a[0][j+1]) swp(0, j);
            if (a[1][j] > a[1][j+1]) swp(1, j);
        }
    }
    cout << ans.size() << '\n';
    for (auto &[x, y] : ans) cout << x+1 << ' ' << y+1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
move all 1->n to a, n+1->2n to b

*/