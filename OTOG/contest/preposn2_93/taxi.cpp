/*
    author  : PakinDioxide
    created : 23/03/2025 18:40
    task    : taxi
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    ll w[n+1], c[n+1];
    w[0] = 0;
    for (int i = 1; i < n; i++) cin >> w[i], w[i] += w[i-1];
    for (int i = 0; i < n; i++) cin >> c[i];
    while (q--) {
        int x, y;
        cin >> x >> y;
        ll mn = LLONG_MAX, co = 0;
        for (int i = x; i >= 0; i--) {
            if (i <= y) mn = min(mn, co + c[i]*(w[y] - w[i]));
            if (i > 0) co += c[i] * (w[i] - w[i-1]);
        }
        cout << mn << '\n';
    }
}