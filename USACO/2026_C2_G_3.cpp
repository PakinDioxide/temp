#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 5e5+5;

int N, F;
int dp[mxN], a[mxN], cyc[mxN], vis[mxN];

int main() {
    cin >> N >> F;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) if (!vis[i]) {
        int x = i;
        vis[x] = 1; x = a[x];
        while (!vis[x]) {
            vis[x] = 1;
            x = a[x];
        }
        if (x == i) {
            cyc[x] = 1;
            x = a[x];
            while (x != i) cyc[x] = 1, x = a[x];
        }
    }
    for (int i = 1; i <= N; i++) dp[i] = INT_MAX;
    while (F--) {
        int x; cin >> x;
        int t = 0;
        while (dp[x] > t) {
            dp[x] = t;
            t++;
            if (cyc[x]) break;
            x = a[x];
        }
    }
    for (int i = 1; i <= N; i++) vis[i] = 0;
    for (int i = 1; i <= N; i++) if (!vis[i] && cyc[i]) {
        int x = i;
        while (1) {
            if (dp[x] < INT_MAX) dp[a[x]] = min(dp[a[x]], dp[x]+1);
            vis[x] = 1;
            x = a[x];
            if (x == i) break;
        }
        while (1) {
            if (dp[x] < INT_MAX) dp[a[x]] = min(dp[a[x]], dp[x]+1);
            x = a[x];
            if (x == i) break;
        }
    }
    for (int i = 1; i <= N; i++) cout << (dp[i] == INT_MAX ? -2 : dp[i] - 1) << '\n';
}

// need to check for -1
