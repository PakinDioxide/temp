#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e4+5;

int n;
ll p[mxN], cp[mxN], pe[mxN], c[mxN], w[mxN], dp[5][mxN];

ll calc(int i, int j, ll x) {
    return -cp[j]*x + dp[i][j] + pe[j];
}

double itc(int x_i, int x_j, int y_i, int y_j) {
    return (double) (calc(x_i, x_j, 0) - calc(y_i, y_j, 0))/(cp[x_j]-cp[y_j]);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i] >> w[i+1];
    n++;
    for (int i = 1; i <= n; i++) p[i] = p[i-1] + w[i], cp[i] = cp[i-1] + c[i], pe[i] = pe[i-1] + p[i] * c[i];
    deque <int> cht; cht.emplace_back(0);
    for (int i = 1; i <= n; i++) dp[1][i] = p[i]*cp[i] - pe[i];
    for (int i = 2; i <= 3; i++) { cht.clear(); cht.emplace_back(0); for (int j = 1; j <= n; j++) {
        while (cht.size() > 1 && calc(i-1, cht[0], p[j]) >= calc(i-1, cht[1], p[j])) cht.pop_front();
        dp[i][j] = p[j]*cp[j] - pe[j] + calc(i-1, cht[0], p[j]);
        while (cht.size() > 1 && itc(i-1, cht[cht.size()-1], i-1, cht[cht.size()-2]) >= itc(i-1, cht[cht.size()-1], i-1, j)) cht.pop_back();
        cht.emplace_back(j);
    }}
    cout << dp[3][n] << '\n';
}

// AC - 08:49 23/06/2025