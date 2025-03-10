#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    ll a[n], b[n];
    set <int> p, q;
    for (int i = 0; i < n; i++) cin >> a[i], p.insert(a[i]);
    for (int i = 0; i < n; i++) cin >> b[i], q.insert(b[i]);
    if (q.size() >= 3 || p.size() >= 3 || (q.size() >= 2 && p.size() >= 2)) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}