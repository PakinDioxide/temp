#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n; cin >> n;
    ll dp[1 << 3];
    for (auto &e : dp) e = LLONG_MAX;
    dp[0] = 0;
    pair <ll, int> a[n];
    for (auto &e : a) {
        string x; cin >> e.first >> x; e.second = 0;
        for (auto &E : x) e.second |= (1 << (E-'A'));
    }
    for (int i = 0; i < (1 << 3); i++) {
        if (dp[i] == LLONG_MAX) continue;
        for (auto &e : a) dp[i|e.second] = min(dp[i|e.second], dp[i] + e.first);
    }
    cout << (dp[(1<<3)-1] == LLONG_MAX ? -1LL : dp[(1<<3)-1]) << '\n';
}