#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int p[n], ss[n], ok = 1, mx = 0;
    p[0] = 1;
    ss[n-1] = 1;
    for (int i = 0; i < n; i++) {
        if (i > 0 && s[i-1] != 'p') p[i] = p[i-1];
        if (i+1 < n && s[i] == 'p') p[i+1] = i+2;
    }
    for (int i = n-1; i >= 0; i--) {
        if (i < n-1 && s[i+1] != 's') ss[i] = ss[i+1];
        if (i-1 >= 0 && s[i] == 's') ss[i-1] = n-i+1;
    }
    for (int i = n-1; i >= 0; i--) {
        mx = max(mx, p[i]);
        if (s[i] != 's') continue;
        if (n-i < mx) {ok = 0; break;}
    }
    mx = 0;
    for (int i = 0; i < n; i++) {
        if (!ok) break;
        mx = max(mx, ss[i]);
        if (s[i] != 'p') continue;
        if (i+1 < mx) {ok = 0; break;}
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}