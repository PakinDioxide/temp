/*
    author  : PakinDioxide
    created : 06/04/2025 22:00
    task    : a
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 1) cout << 4;
    cout << 2025;
    for (int i = 0; i < (n-4)/2; i++) cout << 0 << 0;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}