#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {if (i < n-1) cout << '0'; else cout << '1';}
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}