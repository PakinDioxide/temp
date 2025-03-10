#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        int ok = 1;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            if (abs(a[i] - a[j]) % k == 0) {ok = 0; break;}
        }
        if (ok) {cout << "YES\n" << i+1 << '\n'; return;}
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}