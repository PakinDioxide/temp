#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0 && (i == n-1 || a[i+1] == 0)) cnt++;
    }
    cout << min(cnt, 2) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}