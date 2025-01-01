#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    ll cnt = 0;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    for (int i = 0; i < n-1; i++) {
        int l = lower_bound(a+i+1, a+n, m-a[i]) - a, r = upper_bound(a+i+1, a+n, m-a[i]) - a;
        if (l == n || a[l] != m-a[i]) continue;
        cnt += r-l;
    }
    cout << cnt;
}