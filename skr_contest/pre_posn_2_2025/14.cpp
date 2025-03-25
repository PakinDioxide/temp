/*
    author  : PakinDioxide
    created : 17/03/2025 22:09
    task    : 14
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int ans = INT_MAX;
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= m; b++) {
            if ((n/a)*(m/b) < k) continue;
            ans = min(ans, n*m - a*b*k);
        }
    }
    cout << ans << '\n';
}