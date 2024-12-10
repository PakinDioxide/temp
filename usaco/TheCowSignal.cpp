#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("cowsignal.in", "r", stdin);

    int m, n, t;

    cin >> m >> n >> t;

    vector <string> a(m);

    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    freopen("cowsignal.out", "w", stdout);

    for (int i = 0; i < m; i++) {
        for (int l = 0; l < t; l++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < t; k++) cout << a[i][j];
            }
            cout << "\n";
        }
    }
}
