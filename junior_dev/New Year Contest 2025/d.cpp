// PakinDioxide
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m, cnt = 0;
char a[200][200];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    swap(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    int cnt = 0;
    map <char, int> mp;
    mp['\\'] = 1;
    mp['/'] = 1;
    mp['X'] = 2;
    mp['-'] = 0;
    for (int i = 1; i < n-1; i++) cnt += mp[a[i][0]] + mp[a[i][m-1]];
    for (int i = 1; i < m-1; i++) cnt += mp[a[0][i]] + mp[a[n-1][i]];
    if (n > 1 || m > 1) cnt += mp[a[0][m-1]] + mp[a[0][0]] + mp[a[n-1][0]] + mp[a[n-1][m-1]];
    else cnt += 2*mp[a[0][0]];
    if (n > 1 && m > 1) {
        if (a[0][0] == '/' || a[0][0] == 'X') cnt++;
        if (a[0][m-1] == '\\' || a[0][m-1] == 'X') cnt++;
        if (a[n-1][0] == '\\' || a[n-1][0] == 'X') cnt++;
        if (a[n-1][m-1] == '/' || (a[n-1][m-1] == 'X')) cnt++;
    }
    cnt /= 2;
    cout << cnt;
}