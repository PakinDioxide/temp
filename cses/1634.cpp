#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, x;
    cin >> n >> x;
    vector <int> coins(n), c(x+1);

    for (int i = 0; i < n; i++) cin >> coins[i];

    c[0] = 0;

    for (int i = 1; i <= x; i++) {
        c[i] = INT_MAX;
        for (auto j : coins) if (j <= i) if (c[i] > c[i-j]) c[i] = c[i-j]+1;
    }

    if (c[x] < INT_MAX) cout << c[x];
    else cout << -1;
}
