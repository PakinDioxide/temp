#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e6+5;

int n;
tuple <ll, ll, ll> a[mxN];
ll dp[mxN];

double m(int x, int y) { return (double) (dp[x] - dp[y]) / ((-get<0>(a[y]))-(-get<0>(a[x]))); }

int main() {
    cin >> n;
    for (auto &[x, y, k] : a) cin >> x >> y >> k;
    sort(a, a+n);
    deque <int> dq; dq.emplace_back(0);
    for (int i = 1; i <= n; i++) {
        
    }
}

/*
dp[i] = max(dp[j] + x[i]*y[i] - x[j]*y[i] - a[i])
      = max((-x[j])*y[i] + dp[j]) + x[i]*y[i] - a[i]
m = -x[j]
c = dp[j]
x = y[i]
*/