/*
    author  : PakinDioxide
    created : 20/03/2025 19:18
    task    : 2015_Dec_G_1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool rev(const int &a, const int &b) {
    return b < a;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int n;
    cin >> n;
    int u[2*n+1], a[n];
    vector <int> b;
    memset(u, 0, sizeof(u));
    for (auto &e : a) cin >> e, u[e] = 1;
    for (int i = 1; i <= 2*n; i++) if (!u[i]) b.push_back(i);
    sort(a, a+n/2);
    sort(a+n/2, a+n, rev);
    int ans = 0, idx = 0;
    for (int i = 0; i < n/2; i++) {
        while (idx < n/2 && b[n/2+idx] < a[i]) idx++;
        ans += (idx < n/2);
        idx++;
    }
    idx = n/2-1;
    for (int i = n/2; i < n; i++) {
        while (idx >= 0 && b[idx] > a[i]) idx--;
        ans += (idx >= 0);
        idx--;
    }
    cout << ans << '\n';
}