#include <bits/stdc++.h>
#define ll long long

using namespace std;

#define M vector <vector <double>>

const int mxX = 130;

int N, X;
double P[mxX];
M I, K;

void re(M &x) {
    x.resize(X+1);
    for (auto &e : x) e.resize(X+1);
}

M mult(const M &x, const M &y) {
    M z; re(z);
    for (int i = 0; i <= X; i++) for (int j = 0; j <= X; j++) for (int k = 0; k <= X; k++) z[i][j] += x[i][k] * y[k][j];
    return z;
}

M poww(int y) {
    if (y == 0) return I;
    M k = poww(y/2);
    k = mult(k, k);
    if (y % 2 == 1) k = mult(k, K);
    return k;
}

int main() {
    cin >> N >> X;
    for (int i = 0; i <= X; i++) cin >> P[i];
    for (int i = 0; ; i++) {
        if ((1 << i) - 1 < X) continue;
        X = (1 << i) - 1;
        break;
    }
    re(I), re(K);
    for (int i = 0; i <= X; i++) I[i][i] = 1;
    for (int i = 0; i <= X; i++) for (int j = 0; j <= X; j++) K[i][j] = P[i^j];
    cout << setprecision(6) << 1 - poww(N)[0][0] << '\n';
}
