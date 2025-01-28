#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int a[n];
    for (auto &e : a) cin >> e;
    sort(a, a+n);
    int r = 0, mx = 0;
    for (int l = 0; l < n; l++) {
        while (r < n-1 && a[r+1] - a[l] <= x) r++;
        mx = max(mx, r-l+1);
    }
    cout << mx << '\n';
}