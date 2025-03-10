#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k, p;
    cin >> n >> k >> p;
    if (!(-n*p <= k && k <= n*p)) {cout << -1 << '\n'; return;}
    cout << abs(k/p)+(k%p!=0) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}