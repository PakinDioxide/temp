/*
    author  : PakinDioxide
    created : 15/04/2025 16:21
    task    : 2018_Feb_G_3
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 105;
int n, a[mxN], dp[mxN][mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) dp[i][j] = INT_MAX;
    dp[0][n] = 0;
    for (int x = 1; x <= n; x++) {
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j <= n; j++) if (dp[x-1][j] != INT_MAX) {
                int cnt = 0, idx = 0;
                for (int k = i; k < j; k++) cnt += (idx != a[k]), idx++;
                dp[x][i] = min(dp[x][i], dp[x-1][j] + cnt);
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << dp[i][0] << '\n';
}

/*
mxN = 100

we should use the old zeros first?

let dp[x][i] be the minimum cost if we put x zeros at i and somewhere after i

*/