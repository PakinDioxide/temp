#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (auto &e : a) cin >> e;
    for (auto &e : b) cin >> e;
    int aa[n];
    for (int i = 0; i < n; i++) aa[i] = b[0] - a[i];
    int ok = 1;
    a[0] = min(a[0], aa[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] > aa[i]) swap(a[i], aa[i]);
        if (a[i] >= a[i-1]) continue;
        else if (aa[i] >= a[i-1]) {swap(a[i], aa[i]); continue;}
        else {ok = 0; break;}
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}