#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector <int> k(2*n+5), kk(2*n+5);
    pair <int, int> a[n];
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if (l == r) k[l] = 1, kk[l]++;
        a[i] = {l, r};
    }
    k[0] = 0;
    for (int i = 1; i <= 2*n; i++) k[i] += k[i-1];
    for (int i = 0; i < n; i++) {
        int cnt = k[a[i].second] - k[a[i].first-1];
        if (cnt < a[i].second - a[i].first + 1 || (a[i].first == a[i].second && kk[a[i].first] == 1)) cout << 1;
        else cout << 0;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}