#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char a[n][n], b[m][m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < n-m+1; i++) {
        for (int j = 0; j < n-m+1; j++) {
            int ok = 1;
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < m; y++) {
                    if (a[x+i][y+j] != b[x][y]) {ok = 0; break;}
                }
                if (!ok) break;
            }
            if (ok) {cout << i+1 << ' ' << j+1 << '\n'; return 0;}
        }
    }
}