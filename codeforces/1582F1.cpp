/*
    author  : PakinDioxide
    created : 30/04/2025 23:15
    task    : 1582F1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mX = 605, mxN = 1e5+5;
int dp[mX][mX], n;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    while (n--) {
        int e; cin >> e;
        for (int i = 0; i < mX; i++) dp[i][e] = max(dp[i^e][e], dp[i][e]);
        for (int i = 0; i < mX; i++)
    }
}

/*
there can be at most 2^(ceil(log2(500)))

*/