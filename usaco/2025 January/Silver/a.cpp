#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int a[n+1], b[n+1], dp[n+1];;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    ll p[n+1], s[n+2];
    p[0] = s[n+1] = 0;
    for (int i = 1; i <= n; i++) p[i] = p[i-1] + (a[i] == b[i]);
    for (int i = n; i >= 1; i--) s[i] = s[i+1] + (a[i] == b[i]);
    // 1 center
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = i, r = i;
        ll sum = (a[i] == b[i]);
        ans += sum + p[l-1] + s[r+1];
        // cout << l << ' ' << r << ' ' << sum << '\n';
        while (l-1 > 0 && r+1 <= n) {
            l--, r++;
            sum += (a[l] == b[r]) + (a[r] == b[l]);
            ans += sum + p[l-1] + s[r+1];
            // cout << l << ' ' << r << ' ' << sum << '\n';
        }
    }
    // 2 centers
    for (int i = 1; i <= n-1; i++) {
        int l = i, r = i+1;
        ll sum = (a[l] == b[r]) + (a[r] == b[l]);
        ans += sum + p[l-1] + s[r+1];
        // cout << l << ' ' << r << ' ' << sum << '\n';
        while (l-1 > 0 && r+1 <= n) {
            l--, r++;
            sum += (a[l] == b[r]) + (a[r] == b[l]);
            ans += sum + p[l-1] + s[r+1];
            // cout << l << ' ' << r << ' ' << sum << '\n';
        }
    }
    cout << ans << '\n';
}

// select centers node -> and add 2 of them at the front and back