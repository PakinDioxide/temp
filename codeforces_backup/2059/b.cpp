#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int mrg = n-k, ans = k/2+1, idx = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == idx && mrg > 0) mrg--;
        else if (a[i] == idx) i++, idx++;
        else {cout << idx << '\n'; return;}
    }
    cout << idx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}