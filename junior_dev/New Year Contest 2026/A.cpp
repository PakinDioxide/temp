#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[67];

void solve() {
    ll n; cin >> n;
    cout << (n/67)*dp[66] + dp[n%67] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 1; i < 67; i++) dp[i] = dp[i-1] + i;
    int t; cin >> t;
    while (t--) solve();
}

