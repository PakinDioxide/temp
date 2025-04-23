/*
    author  : PakinDioxide
    created : 09/04/2025 17:20
    task    : 1006F
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, m, k, a[25][25], ans = 0;
unordered_map <ll, int> dp[25][25];

void s1(int x, int y, ll v, int cnt) {
    v ^= a[x][y];
    if (cnt == 0) dp[x][y][v]++;
    else {
        if (x+1 < n) s1(x+1, y, v, cnt-1);
        if (y+1 < m) s1(x, y+1, v, cnt-1);
    }
}

void s2(int x, int y, ll v, int cnt) {
    if (cnt == 0) ans += dp[x][y][k^v];
    else {
        v ^= a[x][y];
        if (x-1 >= 0) s2(x-1, y, v, cnt-1);
        if (y-1 >= 0) s2(x, y-1, v, cnt-1);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    s1(0, 0, 0, (n+m-2)/2);
    s2(n-1, m-1, 0, n+m-2-(n+m-2)/2);
    cout << ans << '\n';
}