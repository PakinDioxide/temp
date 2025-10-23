/*
    author  : 
    created : 25/06/2025 18:21
    task    : 2205
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    auto pt = [&] (int x) {
        for (int i = n-1; i >= 0; i--) cout << (bool) (x & (1 << i));
        cout << '\n';
    };
    int vis[1 << n]; memset(vis, 0, sizeof(vis));
    int x = 0, cnt = 1; vis[0] = 1; pt(0);
    while (cnt < (1 << n)) {
        for (int i = 0; i < n; i++) if (!vis[x ^ (1 << i)]) {
            x ^= (1 << i);
            vis[x] = 1;
            pt(x);
            cnt++;
            break;
        }
    }
}