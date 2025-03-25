#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    a = " " + a, b = " " + b;
    vector <vector <tuple <int, int, int, char>>> dp(n+1, vector <tuple <int, int, int, char>>(m+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) dp[i][j] = {get<0>(dp[i-1][j-1]) + 1, -1, -1, a[i]};
            else if (get<0>(dp[i-1][j]) > get<0>(dp[i][j-1])) dp[i][j] = {get<0>(dp[i-1][j]), -1, 0, 0};
            else dp[i][j] = {get<0>(dp[i][j-1]), 0, -1, 0};
        }
    }
    string s = "";
    int x = n, y = m;
    while (x > 0 && y > 0) {
        if (get<3>(dp[x][y]) != 0) s += get<3>(dp[x][y]);
        int dx = get<1>(dp[x][y]), dy = get<2>(dp[x][y]);
        x += dx, y += dy;
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
}