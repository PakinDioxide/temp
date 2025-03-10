#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    ll a[n+1], p[n+1];
    p[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++) p[i] = a[i] + p[i-1];
    ll ans = LLONG_MAX;
    if (m == 1) {
        int idx = ceil(n/2.0);
        ans = a[idx]*(idx-1) - p[idx-1] + p[n] - p[idx] - a[idx]*(n-idx);
    } else {
        for (int i = 1; i <= n-1; i++) {
            int idx1 = ceil(i/2.0), idx2 = i+ceil((n-i)/2.0);
            ans = min(ans, (a[idx1]*(idx1-1) - p[idx1-1] + p[i] - p[idx1] - a[idx1]*(i-idx1)) + (a[idx2]*(idx2-i-1) - (p[idx2-1]-p[i]) + p[n] - p[idx2] - a[idx2]*(n-idx2)));
        }
    }
    cout << ans << '\n';
}