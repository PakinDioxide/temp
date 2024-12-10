#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    if (i == x && j == y) continue;
                    if ((abs(x-i) == 2 && abs(y-j) == 1) || (abs(x-i) == 1 && abs(y-j) == 2)) continue;
                    ans++;
                }
            }
        }
    }
    return ans / 2;
}

int main() {
    ios::sync_with_stdio(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cout << solve(i) << '\n';
}