#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n; n *= 5;
    int a[n+1]; for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = 0;
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++) a[i] += a[i-1];
    cout << setprecision(12) << fixed << (double) (a[n - n/5] - a[n/5]) / (3*n/5) << '\n';
}