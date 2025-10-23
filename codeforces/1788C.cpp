/*
    author  : 
    created : 01/08/2025 22:06
    task    : 1788C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n; cin >> n;
    if (n % 2 == 0) { cout << "No\n"; return; }
    cout << "Yes\n";
    int vis[2*n+1]; memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= ceil(n/2.0); i++) cout << i << ' ' << 2*n - 2*(i-1) << '\n';
    for (int i = ceil(n/2.0)+1; i <= n; i++) cout << i << ' ' << 2*n - 2*(i-ceil(n/2.0)-1) - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
3 6
2 8
1 10
5 7
4 9
*/