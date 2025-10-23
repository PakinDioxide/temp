#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n >> mod;
    for (int i = n; i <= n; i++) {
        cout << i << ' '; int c = 0;
        for (int j = 2; j <= i && i/j > 1; j++) c++;
        cout << c << '\n';
    }
    // ll dp[n+5], p[n+5];
    // p[0] = 0;
    // dp[1] = 1, p[1] = 1;
    // for (int i = 2; i <= n; i++) {
    //     dp[i] = p[i-1];
    //     for (int j = )
    // }
}

/*
subtradiction -> prefix sum 1 to x-1
2 -> 1 
3 -> 1 1 
4 -> 2 1 1 
5 -> 2 1 1 1 
6 -> 3 2 1 1 1 
7 -> 3 2 1 1 1 1 
8 -> 4 2 2 1 1 1 1 
9 -> 4 3 2 1 1 1 1 1 
10 -> 5 3 2 2 1 1 1 1 1
*/