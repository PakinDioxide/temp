#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size()/2; i++) if (s[i] != s[s.size()-i-1]) {cout << "NO\n"; return;}
    cout << "YES\n";
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}