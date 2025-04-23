/*
    author  : PakinDioxide
    created : 14/04/2025 11:55
    task    : 1082E
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n+1], mx = 0, idx[(int)5e5+5], cnt = 0;
    int p[n+1], dp[n+1];
    p[0] = 0;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) { auto &e = a[i]; cin >> e, cnt += (e == k), p[i] = p[i-1] + (e == k), idx[e] = -1; }
    mx = cnt;
    for (int i = 1; i <= n; i++) {
        if (a[i] == k) continue;
        if (idx[a[i]] == -1) { dp[i] = 1; }
        else { dp[i] = max(dp[idx[a[i]]] + 1 - (p[i] - p[idx[a[i]]]), 1); }
        mx = max(mx, dp[i] + cnt);
        idx[a[i]] = i;
    }
    cout << mx << '\n';
}