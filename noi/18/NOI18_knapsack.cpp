/*
    author  : PakinDioxide
    created : 26/04/2025 23:45
    task    : NOI18_knapsack
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxS = 2005;

vector <pair <int, int>> V[mxS];
int dp[mxS], cnt[mxS], ok[mxS];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int s, n;
    cin >> s >> n;
    while (n--) {
        int v, w, k;
        cin >> v >> w >> k;
        V[w].emplace_back(v, k);
    }
    for (auto &E : V) {
        sort(E.begin(), E.end());
        reverse(E.begin(), E.end());
        for (auto &e : E) swap(e.first, e.second);
        for (int i = 1; i < E.size(); i++) E[i].first += E[i-1].first;
    }
    ok[0] = 1;
    for (int w = 1; w <= s; w++) {
        auto E = V[w];
        if (E.empty()) continue;
        cout << w << '\n';
        for (auto &e : E) cout << "(" << e.first << ' ' << e.second << ')' << ' ';
        cout << '\n';
        memset(cnt, 0, sizeof(cnt));
        for (int i = w; i <= s; i++) {
            if (!ok[i-w]) continue;
            int k = upper_bound(E.begin(), E.end(), make_pair(cnt[i-w]+1, INT_MIN)) - E.begin();
            if (k >= E.size()) continue;
            cout << cnt[i-w]+1 << ' ' << E[k].second << '\n';
            ok[i] = 1;
            if (dp[i] < dp[i-w] + E[k].second) dp[i] = dp[i-w] + E[k].second, cnt[i] = cnt[i-w]+1;
            else if (dp[i] == dp[i-w] + E[k].second && cnt[i] > cnt[i-w]+1) cnt[i] = cnt[i-w]+1;
        }
    }
    int mx = 0;
    for (int i = 1; i <= s; i++) mx = max(mx, dp[i]), cout << dp[i] << ' '; cout << '\n';
    cout << mx << '\n';
}