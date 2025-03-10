#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int n;
        scanf("%d", &n);
        int ans = 0, mx = 0;
        for (int x = 2; x <= n; x++) {
            int k = n/x, sum = k*(k+1)/2*x;
            if (sum > ans) ans = sum, mx = x;
        }
        printf("%d\n", mx);
    }
}