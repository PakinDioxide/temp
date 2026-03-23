#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    tuple <int, int, int, int> tp[n+1];
    for (int i = 1; i <= n; i++) {
        auto &[d, t, p, idx] = tp[i];
        cin >> t >> d >> p;
        idx = i;
    }
    int dp[105][2005];
    pair <int, int> par[105][2005];
    memset(dp, 0, sizeof(dp));
    memset(par, 0, sizeof(par));
    sort(tp+1, tp+n+1);
    for (int i = 1; i <= n; i++) {
        auto &[d, t, p, idx] = tp[i];
        for (int j = 0; j < 2005; j++) dp[i][j] = dp[i-1][j], par[i][j] = make_pair(-(i+1-1), j);
        for (int j = i-1; j >= 0; j--) {
            for (int k = t; k < d; k++) if (dp[i][k] < dp[j][k-t] + p) {
                dp[i][k] = dp[j][k-t] + p;
                par[i][k] = make_pair(j+1, k-t);
            }
        }
        for (int j = 1; j < 2005; j++) if (dp[i][j] < dp[i][j-1]) {
            dp[i][j] = dp[i][j-1];
            par[i][j] = make_pair(-(i+1), j-1);
        }
    }
    int mx = 0, A = -1, B = -1;
    for (int i = 1; i <= n; i++) for (int j = 0; j < 2005; j++) {
        if (mx < dp[i][j]) mx = dp[i][j], A = i, B = j;
    }
    if (A == -1) { cout << 0 << '\n' << 0 << '\n' << '\n'; return 0; }
    cout << mx << '\n';
    vector <int> v;
    while (A != 0) {
        v.emplace_back(get<3>(tp[A]));
        int tA = par[A][B].first;
        int tB = par[A][B].second;
        A = tA, B = tB;
        if (A < 0) v.pop_back(), A = -A;
        A--;
    }
    cout << v.size() << '\n';
    reverse(v.begin(), v.end());
    for (auto &e : v) cout << e << ' '; cout << '\n';
}

