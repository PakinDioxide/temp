#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long a[n], l = 0, r = n-1, kk = 0, ans = 0;
        for (long long i = 0; i < n; i++) cin >> a[i];
        while (k > 0 && l <= r) {
            if (kk == 0 && a[l] <= k) {if (--a[l] == 0) {ans++; l++;} kk = 1; k--;}
            else if (kk == 1 && a[r] <= k) {if (--a[r] == 0) {ans++; r--;} kk = 0; k--;}
            else break;
        }
        cout << ans << '\n';
    }
}