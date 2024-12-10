#include <bits/stdc++.h>

using namespace std;

#define int long long

int a[100005][26];

int32_t main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= 5*n; i++) {
        for (int j = 1; j <= 5*n; j++) {
            if (i <= n && j > n && j <= 4*n) printf("#");
            else if (i > n && i <= 4*n && j <= n) printf("#");
            else if (i > 4*n && j > n && j <= 4*n) printf("#");
            else if (i > 2*n && i <= 3*n && j > 3*n) printf("#");
            else if (i > 3*n && i <= 4*n && j > 4*n) printf("#");
            else printf(".");
        }
        printf("\n");
    }
}