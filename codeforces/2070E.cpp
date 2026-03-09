#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

const int mxN = 3e5+5;

int N, P[mxN], fen[4][mxN*4], T[4] = {0, 1, 1, -2}, ans = 0;

void upd(int idx, int x, int k) { for (int i = idx; i <= 4*N+1; i += i & -i) fen[k][i] += x; }
int qr(int idx, int k) { int x = 0; for (int i = idx; i > 0; i -= i & -i) x += fen[k][i]; return x; }

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    string S; cin >> S;
    for (int i = 0; i < N; i++) P[i+1] = P[i] + (S[i] == '0' ? 1 : -3);
    int O = 3*N+1;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < 4; j++) {
            ans += qr(P[i] - T[(i-j+4)%4] + O - 1, j);
        }
        upd(P[i] + O, 1, i % 4);
    }
    cout << ans << '\n';
}

