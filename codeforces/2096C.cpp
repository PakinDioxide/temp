/*
    author  : PakinDioxide
    created : 19/04/2025 21:45
    task    : 2096C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    ll a[n][n], wi[n], wj[n];
    for (auto &E : a) for (auto &e : E) cin >> e;
    for (auto &e : wi) cin >> e;
    for (auto &e : wj) cin >> e;
    ll pir[n], pil[n], pirx[n], pilx[n], mxi = 0;
    memset(pir, 0, sizeof(pir));
    memset(pil, 0, sizeof(pil));
    memset(pirx, 0, sizeof(pirx));
    memset(pilx, 0, sizeof(pilx));
    for (int i = 0; i < n-1; i++) for (int j = 0; j < n; j++) pir[i] = max(pir[i], (ll)(a[i][j]+1 == a[i+1][j])), pirx[i] = max(pirx[i], (ll)(a[i][j] == a[i+1][j])), mxi = max(mxi, pirx[i]);
    for (int i = n-1; i > 0; i--) for (int j = 0; j < n; j++) pil[i] = max(pil[i], (ll)(a[i][j]+1 == a[i-1][j])), pilx[i] = max(pilx[i], (ll)(a[i][j] == a[i-1][j])), mxi = max(mxi, pilx[i]);
    ll dpir[n], dpil[n];
    memset(dpir, 0, sizeof(dpir));
    memset(dpil, 0, sizeof(dpil));
    int l = -1;
    for (int i = 0; i < n; i++) {
        dpil[i] = wi[i];
        if (pil[i]) dpil[i] += dpil[i-1];
        else if (l >= 0) dpil[i] += dpil[l];
        if (pilx[i]) l = i;
    }
    l = -1;
    for (int i = n-1; i >= 0; i--) {
        dpir[i] = wi[i];
        if (pir[i]) dpir[i] += dpir[i+1];
        else if (l >= 0) dpir[i] += dpir[l];
        if (pirx[i]) l = i;
    }

    ll pjr[n], pjl[n], pjrx[n], pjlx[n], mxj = 0;
    memset(pjr, 0, sizeof(pjr));
    memset(pjl, 0, sizeof(pjl));
    memset(pjrx, 0, sizeof(pjrx));
    memset(pjlx, 0, sizeof(pjlx));
    for (int i = 0; i < n-1; i++) for (int j = 0; j < n; j++) pjr[i] = max(pjr[i], (ll)(a[j][i]+1 == a[j][i+1])), pjrx[i] = max(pjrx[i], (ll)(a[j][i] == a[j][i+1])), mxj = max(mxj, pjrx[i]);;
    for (int i = n-1; i > 0; i--) for (int j = 0; j < n; j++) pjl[i] = max(pjl[i], (ll)(a[j][i]+1 == a[j][i-1])), pjlx[i] = max(pjlx[i], (ll)(a[j][i] == a[j][i-1])), mxj = max(mxj, pjrx[i]);;
    ll dpjr[n], dpjl[n];
    memset(dpjr, 0, sizeof(dpjr));
    memset(dpjl, 0, sizeof(dpjl));
    l = -1;
    for (int i = 0; i < n; i++) {
        dpjl[i] = wj[i];
        if (pjl[i]) dpjl[i] += dpjl[i-1];
        else if (l >= 0) dpjl[i] += dpjl[l];
        if (pjlx[i]) l = i;
    }
    l = -1;
    for (int i = n-1; i >= 0; i--) {
        dpjr[i] = wj[i];
        if (pjr[i]) dpjr[i] += dpjr[i-1];
        else if (l >= 0) dpjr[i] += dpjr[l];
        if (pjrx[i]) l = i;
    }
    for (int i = 0; i < n; i++) cout << dpil[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) cout << dpir[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) cout << dpjl[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) cout << dpjr[i] << ' ';
    cout << '\n';
    ll mn1 = LLONG_MAX, mn2 = LLONG_MAX;
    if (!mxi) mn1 = 0;
    if (!mxj) mn2 = 0;
    for (int i = 0; i < n; i++) {
        mn1 = min(mn1, dpil[i] + dpir[i] - wi[i]);
        mn2 = min(mn2, dpjl[i] + dpjr[i] - wj[i]);
    }
    cout << (mn1 == LLONG_MAX || mn2 == LLONG_MAX ? -1 : mn1 + mn2) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
if same horizontal, can fix only with j
else if same vertical, can fix only with i

adding i and j are not revelant

let dp[i] be the minimum cost to fix if we add at i

we should do from both ways

1 2 5 9 
0 9 7 4 
5 11 18 19 
26 21 15 8 
19

*/