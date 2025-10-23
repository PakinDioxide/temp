/*
    author  : 
    created : 21/06/2025 21:39
    task    : 2120B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; ll s; cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int dx, dy; ll x, y; cin >> dx >> dy >> x >> y;
        if ((x == y && dx == dy) || (x+y == s && dx != dy)) ans++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
the collision between 2 balls doesn't change anything..
we just check that does a ball go to the hole
*/