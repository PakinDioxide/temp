/*
    author  : PakinDioxide
    created : 13/03/2025 16:51
    task    : 2018_Opn_B_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    int a[n+1], b[m], f[n+1];
    vector <int> v;
    memset(a, 0, sizeof(a));
    memset(f, 0, sizeof(f));
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < k; i++) {
        int p, q;
        cin >> p >> q;
        f[p] = q;
        a[q] = p;
    }
    if (f[1]) {cout << f[1] << '\n'; return 0;}
    for (int i = 1; i <= n; i++) {
        if (a[i]) continue;
        a[i] = 1;
        f[1] = 1;
        int idx = 0;
        for (int j = 1; j <= n; j++) {
            if (idx == m) break;
            if (a[j]) {
                if (a[j] == b[idx]) idx++;
                continue;
            }
            if (!f[b[idx]]) idx++;
        }
        if (idx == m) {cout << i << '\n'; return 0;}
        a[i] = 0;
    }
}