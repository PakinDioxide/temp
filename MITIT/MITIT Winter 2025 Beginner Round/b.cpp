#include <bits/stdc++.h>
#define ll long long

using namespace std;

int solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] != 'M' || s[n-1] == 'M') return 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == 'M' && s[i-1] == 'M') return 0;
        else if (s[i] == 'M') continue;
        if (!(i < n-1 && s[i] == 'I' && s[i+1] == 'T')) return 0;
        else i++;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) cout << (solve() ? "YES\n" : "NO\n");
}