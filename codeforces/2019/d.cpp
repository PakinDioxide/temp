#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int time = 1;
    unordered_set <int> dp[n][n];
    for (int i = 0; i < n; i++) dp[i][i].insert(i);
    for (int k = 1; k < n; k++) {
        time++;
        for (int i = 0; i < n-k; i++) {
            int j = i + k;
            if (a[j] >= time) dp[i][j] = dp[i][j-1];
            if (a[i] >= time) {
                unordered_set <int> x = dp[i+1][j];
                if (dp[i][j].size() < x.size()) swap(x, dp[i][j]);
                for (int i : x) dp[i][j].insert(i);
            }
        }
    }
    printf("%d\n", dp[0][n-1].size());
} // มันเคยมี  cnc ข้อนึงที่ทำแบบนี้ปะ คล้ายๆ แบบ small to large merge ที่เอากราฟมารวมกัน ปี pre toi20 น่าจะ output มันผิดอะ

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}