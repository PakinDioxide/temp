#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, cnt = 0;
    cin >> n >> m;
    int a[n+2][m+2];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
    int k;
    cin >> k;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cnt += (a[i][j-1] + a[i][j+1] == k);
    cout << cnt;
}