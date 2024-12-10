#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("speeding.in", "r", stdin);

    int m, n;

    cin >> n >> m;

    int sl[100], cs[100];

    int cur = 0;

    for (int i = 0; i < n; i++) {
        int a, b;

        cin >> a >> b;

        int ma = cur + a;

        for (; cur < ma; cur++) {
            sl[cur] = b;
        }
    }

    cur = 0;

    for (int i = 0; i < m; i++) {
        int a, b;

        cin >> a >> b;

        int ma = cur + a;

        for (; cur < ma; cur++) {
            cs[cur] = b;
        }
    }

    int ans = 0;

    for (int i = 0; i < 100; i++) {
        if (ans < cs[i] - sl[i]) ans = cs[i] - sl[i];
    }

    freopen("speeding.out", "w", stdout);
    cout << ans;
}
