#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n+1][n+1];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
    for (int i = 1; i < n; i++){
        int b[n+1];
        for (int &e : b) e = 1;
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 2) for (int x = max(1, j-k))
        }
    }
}