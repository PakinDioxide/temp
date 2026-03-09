#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    int a[n], b[n];
    for (auto &e : a) cin >> e;
    for (auto &e : b) cin >> e;
    map <ll, int> mp;
    int rc = 0, l = 0;
    for (int i = 0; i <= n; i++) {
        if (i == n || (rc == 0 && b[i] % 2 == 1 && i != 0)) {
            multiset <int> A, B;
            for (int j = l; j < i; j++) A.emplace(a[j]), B.emplace(b[j]);
            if (A != B) { cout << "NO\n"; return; }
            l = i;
        }
        if (i == n) break;
        rc = b[i] % 2;
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

