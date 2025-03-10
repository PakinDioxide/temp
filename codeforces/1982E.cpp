#include <bits/stdc++.h>

using namespace std;

#define int long long

map <int, int> memo;

int find(int x, int k) {
    if (memo[x] > 0) return memo[x];
    for (int i = k; i >= 0; i--) {
        if (x & (1 << i)) return memo[x] = 1 + find(x ^ (1 << i), i-1);
    }
}

int32_t main() {
    memo[1] = 1;
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int sum = 0, c = 1;
        for (int i = 1; i <= n; i++) {
            int j = find(i);
            if (j)
        }
    }
}