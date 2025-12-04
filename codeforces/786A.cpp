#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    int a[n+1][2]; memset(a, 0, sizeof(a));
    int p[n+1][2]; memset(p, 0, sizeof(p));
    int k1, k2;
    vector <int> d[2]; 
    cin >> k1; d[0].resize(k1); for (auto &x : d[0]) cin >> x, a[x][0] = 1, p[n-x+1][0] = 1;
    cin >> k2; d[1].resize(k2); for (auto &x : d[1]) cin >> x, a[x][1] = 1, p[n-x+1][1] = 1;
    for (int o = 0; o < n+n/2; o++) {
        for (int i = n; i >= 2; i--) {
            if (!p[i][0]) {
                int mn = 1;
                for (auto &x : d[0]) mn = min(mn, p[(i+x > n ? i+x-n : i+x)][1]);
                p[i][0] = -mn;
            }
            if (!p[i][1]) {
                int mn = 1;
                for (auto &x : d[1]) mn = min(mn, p[(i+x > n ? i+x-n : i+x)][0]);
                p[i][1] = -mn;
            }
        }
    }
    for (int i = 2; i <= n; i++) cout << (p[i][0] == 0 ? "Loop" : p[i][0] == 1 ? "Win" : "Lose") << ' '; cout << '\n';
    for (int i = 2; i <= n; i++) cout << (p[i][1] == 0 ? "Loop" : p[i][1] == 1 ? "Win" : "Lose") << ' '; cout << '\n';
}