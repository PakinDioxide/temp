/*
    author  : PakinDioxide
    created : 27/03/2025 22:13
    task    : 2019_Dec_B_1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int n, k;
    cin >> k >> n;
    int a[k][n], cnt = 0;
    for (int i = 0; i < k; i++) for (int j = 0; j < n; j++) {int x; cin >> x; x--; a[i][x] = j;}
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        int ok = 1;
        for (int o = 0; o < k; o++) ok = min(ok, (int) (a[o][i] < a[o][j]));
        cnt += ok;
    }
    cout << cnt << '\n';
}