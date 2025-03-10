#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (auto &e : a) cin >> e;
    sort(a, a+n);
    int ok = 1;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = i; a[i] == a[j]; j++) cnt++;
        if (cnt == 1) {ok = 0; break;}
        else if (cnt == 2) {i += cnt-1; continue;}
        for (int j = i+2; a[i] == a[j]; j++) a[j]++;
        i++;
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