#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    int a[n][n]; for (auto &E : a) for (auto &e : E) e = -1;
    int it = 1;
    int r = 0, c = (n-1)/2;
    a[r][c] = 1;
    for (int o = 0; o < n*n-1; o++) {
        if (a[(r-1 + n)%n][(c+1)%n] == -1) a[r = (r-1+n)%n][c = (c+1)%n] = ++it;
        else a[r = (r+1)%n][c] = ++it;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << a[i][j] << ' ';
        cout << '\n';
    }
}

