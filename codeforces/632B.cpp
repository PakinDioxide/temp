#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n; cin >> n;
    ll p[n+1], a[n+1];
    p[0] = a[0] = 0;
    for (int i = 1; i <= n; i++) cin >> p[i];
    char s[n+1];
    for (int i = 1; i <= n; i++) cin >> s[i], a[i] = a[i-1], a[i] += (s[i] == 'B' ? p[i] : 0);
    for (int i = 1; i <= n; i++) p[i] += p[i-1];
    ll mx = a[n];
    for (int i = 1; i <= n; i++) mx = max(mx, a[n] - a[i] + (p[i] - a[i]));
    for (int i = n; i >= 1; i--) mx = max(mx, a[i-1] + ((p[n] - p[i-1]) - (a[n] - a[i-1])));
    cout << mx << '\n';
}
