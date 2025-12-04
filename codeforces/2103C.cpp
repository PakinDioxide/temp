#include <bits/stdc++.h>
#define ll long long

using namespace std;

int solve() {
    int n, k; cin >> n >> k;
    int a[n]; for (auto &e : a) cin >> e, e = (e > k ? -1 : 1);
    int p[n], s[n], pp[n], ss[n];
    for (int i = 0; i < n; i++) p[i] = (i > 0 ? p[i-1] : 0) + a[i], pp[i] = max(p[i], (i > 0 ? pp[i-1] : INT_MIN));
    for (int i = n-1; i >= 0; i--) s[i] = (i < n-1 ? s[i+1] : 0) + a[i], ss[i] = max(s[i], (i < n-1 ? ss[i+1] : INT_MIN));
    for (int i = 0; i < n-2; i++) if (pp[i] >= 0 && ss[i+2] >= 0) return 1;
    int ps[n], sp[n]; ps[0] = sp[n-1] = INT_MIN;
    for (int i = 1; i < n; i++) ps[i] = max(s[i], ps[i-1]);
    for (int i = n-2; i >= 0; i--) sp[i] = max(p[i], sp[i+1]);
    for (int i = 0; i < n-2; i++) if (p[i] >= 0 && sp[i+1] >= p[i]) return 1;
    for (int i = 2; i < n; i++) if (s[i] >= 0 && ps[i-1] >= s[i]) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) cout << (solve() ? "YES\n" : "NO\n");
}