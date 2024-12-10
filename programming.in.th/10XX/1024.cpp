#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    cin >> a[0];
    for (int i = 1; i < n; i++) {cin >> a[i]; a[i] += a[i-1];}
    int aa, b, c, ans = INT_MAX, l, r;
    for (int i = 1; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            aa = a[i-1];
            b = a[j-1] - a[i-1];
            c = a[n-1] - a[j-1];
            int mm = max({aa, b, c}) - min({aa, b, c});
            if (mm < ans) {
                l = i+1;
                r = j+1;
                ans = mm;
            }
        }
    }
    cout << l << ' ' << r;
}