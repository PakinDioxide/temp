#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, ok = 1;
    scanf("%d", &n);
    char s[n];
    scanf("%s", &s);
    int k = sqrt(n);
    if (k*k != n) {printf("No\n"); return;}
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if ((i == 0 || i == k-1 || j == 0 || j == k-1) && s[i*k + j] == '0') ok = 0;
            else if (!(i == 0 || i == k-1 || j == 0 || j == k-1) && s[i*k + j] == '1') ok = 0;
            if (ok == 0) break;
        }
        if (ok == 0) break;
    }
    if (ok) printf("Yes\n");
    else printf("No\n");
} 

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}