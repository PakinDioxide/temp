#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cl[n+1], cnt = 0;
    s = ' ' + s;
    cl[0] = 0;
    for (int i = 1; i <= n; i++) {
        cl[i] = cl[i-1] + (s[i] == '_');
        if (s[i] != '_') cnt += cl[i];
    }
    if (cnt%2) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}