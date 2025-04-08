/*
    author  : PakinDioxide
    created : 29/03/2025 21:42
    task    : 2092C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    ll a[n], mx = 0, cnt = 0, ce = 0, co = 0;
    for (auto &e : a) {
        cin >> e;
        if (e % 2 == 0) cnt += e, ce = 1;
        else cnt += e-1, co = 1;
        mx = max(mx, e);
    }
    if (ce && co) cout << cnt + 1 << '\n';
    else cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}