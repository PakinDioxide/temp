#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size()-2; i++) cout << s[i];
    cout << "i\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}