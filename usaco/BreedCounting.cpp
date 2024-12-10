#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int n, q;

    cin >> n >> q;

    long long c[n+1][3];

    c[0][0] = c[0][1] = c[0][2] = 0;

    for (int i = 0; i < n; i++) {
        int a;

        cin >> a;

        a--;

        for (int j = 0; j < 3; j++) {
            if (j == a) c[i+1][j] = c[i][j] + 1;
            else c[i+1][j] = c[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;

        cin >> a >> b;

        a--;

        cout << c[b][0] - c[a][0] << " " << c[b][1] - c[a][1] << " " << c[b][2] - c[a][2] << "\n";
    }
}
