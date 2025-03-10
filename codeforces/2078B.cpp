#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n-2; i++) cout << n - ((k+1)%2) << ' ';
    cout << n << ' ' << n-1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}