#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n*2+1][n*2+1];
    memset(a, 0, sizeof(a));
    int x = ceil(n/2.0), y = ceil((n+1)/2.0), xx = n+x, yy = n+y;
    x--, y--;
    for (int i = 0; i < ceil(n/2.0); i++) {
        for (int j = 0; j <= i; j++) {
            a[i][x-j] = 1;
            a[i][y+j] = 1;
            a[i][xx-j] = 1;
            a[i][yy+j] = 1;
        }
    }
    for (int i = ceil(n/2.0); i < ceil(n/2.0)+n; i++) {
        for (int j = i-ceil(n/2.0)+1; j < 2*n+1 - (i-ceil(n/2.0)+1); j++) a[i][j] = 1;
    }
    for (int i = 0; i < ceil(n/2.0)+n; i++) {
        for (int j = 0; j < n*2+1; j++) cout << (a[i][j] == 1 ? '*' : '-');
        cout << '\n';
    }
}