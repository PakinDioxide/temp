/*
    author  : PakinDioxide
    created : 13/04/2025 22:35
    task    : 2094B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    int d = n-m;
    int L = l, R = r;
    R -= d;
    if (R < 0) L += (0-R), R = 0;
    cout << L << ' ' << R << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}