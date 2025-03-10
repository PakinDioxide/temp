#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string s, t = "";
    cin >> s;
    for (char i : s) t += (i == 'p' ? 'q' : (i == 'q' ? 'p' : 'w'));
    reverse(t.begin(), t.end());
    cout << t << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}