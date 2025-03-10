#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n], ok = 1;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) if (abs(a[i+1] - a[i]) != 5 && abs(a[i+1] - a[i]) != 7) {ok = 0; break;}
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}