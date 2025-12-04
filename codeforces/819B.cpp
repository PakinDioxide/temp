#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    ll a[n+1]; for (int i = 1; i <= n; i++) cin >> a[i];
    ll p[2*n+5], s[2*n+5]; memset(p, 0, sizeof(p)), memset(s, 0, sizeof(s));
    for (int i = 1; i <= n; i++) {
        int idx = (a[i] - i + n) % n + 1;
        // cout << idx << '\n';
        p[idx+1]++;
        p[idx+(n-a[i])+1]--;
        p[idx+(n-a[i])+1] -= (n-a[i]);
        p[idx+(n-a[i])+2] += (n-a[i]);
        idx += n;
        s[idx-1]++;
        if (idx-a[i] >= 0) s[idx-(a[i])]--, s[idx-(a[i])] -= a[i] - 1;
        if (idx-a[i]-1 >= 0) s[idx-(a[i])-1] += a[i] - 1;
    }
    for (int i = 1; i <= 2*n; i++) p[i] += p[i-1];
    for (int i = 2*n; i >= 1; i--) s[i] += s[i+1];
    // for (int i = 1; i <= 2*n; i++) cout << s[i] << ' '; cout << '\n';
    for (int i = 1; i <= 2*n; i++) p[i] += p[i-1];
    for (int i = 2*n; i >= 1; i--) s[i] += s[i+1];
    // for (int i = 1; i <= 2*n; i++) cout << s[i] << ' '; cout << '\n';
    ll k[n+1], mn = LLONG_MAX, idx = -1;
    for (int i = 1; i <= n; i++) {
        k[i] = p[i] + s[i] + p[i+n] + s[i+n];
        if (k[i] < mn) mn = k[i], idx = i-1;
    }
    cout << mn << ' ' << idx << '\n';
}