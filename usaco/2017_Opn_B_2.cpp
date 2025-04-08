/*
    author  : PakinDioxide
    created : 28/03/2025 03:13
    task    : 2017_Opn_B_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    string a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int cnt = 0;
    for (int j = 0; j < m; j++) {
        int A = 0, T = 0, G = 0, C = 0, ok = 1;
        for (int i = 0; i < n; i++) {
            if (a[i][j] == 'A') A = 1;
            else if (a[i][j] == 'T') T = 1;
            else if (a[i][j] == 'G') G = 1;
            else C = 1;
        }
        for (int i = 0; i < n; i++) {
            if (b[i][j] == 'A') ok = min(ok, (int) !A);
            else if (b[i][j] == 'T') ok = min(ok, (int) !T);
            else if (b[i][j] == 'G') ok = min(ok, (int) !G);
            else ok = min(ok, (int) !C);
        }
        cnt += ok;
    }
    cout << cnt << '\n';
}