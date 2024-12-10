#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int n, m, ans = 0;
        cin >> n >> m;

        for (int x = 1; x < n; x++) {
            for (int y = x+1; y <= n; y++) {
                if ((m%x)%y == (m%y)%x) ans++;
            }
        }
        cout << ans << '\n';
    }
}
