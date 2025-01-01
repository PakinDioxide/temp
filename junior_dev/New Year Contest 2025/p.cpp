// PakinDioxide
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    ll a[n+1], b[n+1];
    vector <pair <int, int>> v;
    for (int i = 1; i <= n; i++) cin >> a[i], v.emplace_back(a[i], i);
    for (int i = 1; i <= n; i++) cin >> b[i];
    pair <int, ll> l[n+1], r[n+1];
    stack <pair <int, int>> st;
    for (int i = 1; i <= n; i++) {
        l[i] = {0, 0};
        while (!st.empty() && st.top().first <= a[i]) st.pop();
        if (!st.empty()) l[i] = {st.top().second, (b[st.top().second] ^ b[i])};
        st.emplace(a[i], i);
    }
    while (!st.empty()) st.pop();
    for (int i = n; i >= 1; i--) {
        r[i] = {0, 0};
        while (!st.empty() && st.top().first <= a[i]) st.pop();
        if (!st.empty()) r[i] = {st.top().second, (b[st.top().second] ^ b[i])};
        st.emplace(a[i], i);
    }

    sort(v.begin(), v.end());
    ll dp[n+1][35];
    for (int i = 1; i <= n; i++) for (int j = 0; j <= 30; j++) dp[i][j] = LLONG_MAX;
    for (int i = 0; i <= 30; i++) dp[v[n-1].second][i] = 0;
    for (int i = n-1; i >= 1; i--) {
        int idx = v[i-1].second;
        // cout << l[idx].first << ' ' << r[idx].first << '\n';
        if (l[idx].first == 0 || r[idx].first == 0) {
            int p, q;
            if (l[idx].first == 0) p = r[idx].first, q = r[idx].second;
            else p = l[idx].first, q = l[idx].second;
            for (int j = 0; j <= 30; j++) {
                if (dp[p][j] == LLONG_MAX) {if (j > 0) dp[i][j] = dp[i][j-1];}
                else dp[i][j] = dp[p][j] + q;
            }
        } else {
            if (a[l[idx].first] > a[r[idx].first]) {
                for (int j = 1; j <= 30; j++) {
                    if (dp[l[idx].first][j-1] == LLONG_MAX) {if (j > 0) dp[i][j] = dp[i][j-1];}
                    else dp[i][j] = dp[l[idx].first][j-1] + l[idx].second;
                }
                for (int j = 0; j <= 30; j++) {
                    if (dp[r[idx].first][j] == LLONG_MAX) {if (j > 0) dp[i][j] = dp[i][j-1];}
                    else dp[i][j] = min(dp[i][j], dp[r[idx].first][j] + l[idx].second);
                }
            }
        }
        cout << dp[idx][0] << ' ';
    }

    while (q--) {
        int x, y, k;
        cin >> x >> y >> k;
        cout << dp[x][0] + dp[y][0] << '\n';
    }
}