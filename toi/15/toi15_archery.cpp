#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m = INT_MAX, ans = INT_MAX, p;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m = min(a[i], m);
    }
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 1; i <= m; i++) {
        int k = 0;
        for (int j = 0; j < n; j++) {
            if (i <= b[j]) k += b[j] - i;
            else k += a[j] - i + b[j]; 
        }
        if (ans > k) {
            ans = k;
            p = i;
        }
    }
    cout << p << ' ' << ans;
}