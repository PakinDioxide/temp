/*
    author  : PakinDioxide
    created : 24/04/2025 21:36
    task    : 2106B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) cout << i << ' ';
    for (int i = n-1; i >= k; i--) cout << i << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}