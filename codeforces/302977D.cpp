#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

ll n, k, p[mxN], pe[mxN], a[mxN], mx = 0;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], p[i] = p[i-1] + a[i];
    for (int i = 1, x; i <= n; i++) cin >> x, pe[i] = pe[i-1] + x*a[i];
    for (int i = 1; i <= n-k+1; i++) {
        mx = max(mx, pe[i-1] + p[i+k-1] - p[i-1] + pe[n] - pe[i+k-1]);
    }
    cout << mx << '\n';
}