#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, l, r; cin >> n >> l >> r;
    unordered_map <int, int> vis;
    int it = 1, x = 0, a[n]; vis[0] = 1;
    for (int i = 1; i < r; i++) {
        while (vis[it]) it++;
        a[i] = x^it;
        x ^= a[i];
        vis[x] = 1;
    }
    
    // a[l] = 1e8;
    int xx = 0;
    for (int i = l; i < r; i++) xx ^= a[i];
    a[r] = xx;
    x ^= xx;
    vis[x] = 1;
    for (int i = r+1; i <= n; i++) {
        while (vis[it]) it++;
        a[i] = x^it;
        x ^= a[i];
        vis[x] = 1;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << ' '; cout << '\n';
    // for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) {
    //     int xx = 0;
    //     for (int k =i ; k <= j; k++) xx ^= a[k];
    //     if (xx == 0 && (i != l || j != r)) {cout << i << ' ' << j << '\n'; exit(1);}
    // }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}