/*
    author  : 
    created : 01/07/2025 21:35
    task    : 2123A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    if (n % 4) cout << "Alice\n";
    else cout << "Bob\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}