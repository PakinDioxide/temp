#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;

    cin >> n >> q;

    int sum[n+1][n+1];

    for (int i = 0; i <= n; i++) {
        sum[0][i] = sum[i][0] = 0;
    }

    for (int i = 0; i < n; i++) {
        string s;

        cin >> s;

        for (int j = 0; j < n; j++) {
            sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j];
            if (s[j] == '*') sum[i+1][j+1]++;
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b, c, d;

        cin >> a >> b >> c >> d;
        a--;
        b--;

        cout << sum[c][d] - sum[c][b] - sum[a][d] + sum[a][b] << "\n";
    }
}
