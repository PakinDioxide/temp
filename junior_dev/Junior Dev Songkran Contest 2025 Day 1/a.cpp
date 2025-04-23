/*
TASK: Touching
LANG: C++
AUTHOR: PakinDioxide
CENTER: TU
*/
/*
    author  : PakinDioxide
    created : 13/04/2025 18:07
    task    : a
*/
#include <bits/stdc++.h>
#define ll long long
// #define int ll

#pragma GCC optimize("O2")
#pragma GCC target("avx2")

using namespace std;

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    int n, m, r;
    // cin >> r;
    cin >> r >> n >> m;
    char a[2*r+1][2*r+1];
    for (int i = 0; i < 2*r+1; i++) for (int j = 0; j < 2*r+1; j++) a[i][j] = '.';
    for (int i = 0; i < 2*r+1; i++) for (int j = 0; j < 2*r+1; j++) {
        if ((i-r)*(i-r) + (j-r)*(j-r) < (r+1)*(r+1) && j == r) a[i][j] = '|';
        if ((i-r)*(i-r) + (j-r)*(j-r) < (r+1)*(r+1) && i == r) a[i][j] = '-';
        if ((i-r)*(i-r) + (j-r)*(j-r) < (r+1)*(r+1) && (i == j || i+j == 2*r)) a[i][j] = '#';
    }
    for (int i = 0; i < 2*r+1; i++) for (int j = 0; j < 2*r+1; j++) {
        if ((i-r)*(i-r) + (j-r)*(j-r) < (r+1)*(r+1) && (i-r)*(i-r) + (j-r)*(j-r) >= r*r) a[i][j] = '*';
    }
    for (int i = 0; i < 2*r+1; i++) for (int j = 0; j < 2*r+1; j++) {
        if ((i-r)*(i-r) + (j-r)*(j-r) < (r-2)*(r-2) && (i-r)*(i-r) + (j-r)*(j-r) >= (r-3)*(r-3)) a[i][j] = '*';
    }
    int k = 2*r+1;
    n *= k, m *= k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s == "MisterO") cout << a[i%k][j%k];
            else if (s == "Pasit") cout << a[i%k][((j%k)+k-((i/k)%k))%k];
            else cout << a[i%k][((j%k)+i/k)%k];
        }
        cout << '\n';
    }
}