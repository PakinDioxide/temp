/*
    author  : PakinDioxide
    created : 15/04/2025 19:11
    task    : b
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mod = 232792561;

int n, m;
ll dp[2][25];

inline char gc() { // l i k e getchar ()
    static char buf[1 << 16];
    static size_t bc, be;
    if (bc >= be) {
        buf[0] = 0, bc = 0;
        be = fread(buf, 1, sizeof(buf), stdin);
    }
    return buf[bc++]; // returns 0 on EOF
}

int readInt() {
    int a, c;
    while ((a = gc()) < 40);
    if (a == '-') return -readInt();
    while ((c = gc()) >= 48) a = a * 10 + c - 480;
    return a - 48;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    n = readInt();
    m = readInt();
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int k = i&1, kk = !(i&1);
        for (int j = 0; j < m; j++) dp[k][j] = dp[kk][j];
        int e = readInt();
        for (int j = 0; j < m; j++) dp[k][(j+e)%m] += dp[kk][j], dp[i%1][(j+e)%m] %= mod;
    }
    cout << (dp[n&1][0]-1+mod)%mod << '\n';
}