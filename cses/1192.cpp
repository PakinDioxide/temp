#include <bits/stdc++.h>

using namespace std;

vector <string> v;
int m, n;

void f(int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n || v[i][j] != '.') return;

    v[i][j] = '#';

    f(i+1, j);
    f(i-1, j);
    f(i, j+1);
    f(i, j-1);
}

int main() {
    cin >> m >> n;

    v.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }

    int ans = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == '.') {
                ans++;
                f(i, j);
            }
        }
    }

    cout << ans;
}
