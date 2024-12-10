#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, cnt = 0, ok = 1;
    cin >> n >> k;
    vector <int> vis(n+1), a(n+1);
    for (int i = 2; i <= n; i++) cin >> a[i];
    while (k != 1) {
        if (vis[k]) {ok = 0; break;}
        vis[k] = 1;
        k += a[k];
        while (k <= 0) k += n;
        while (k > n) k -= n;
        cnt++;
    }
    if (!ok) cout << -1;
    else cout << cnt;
}