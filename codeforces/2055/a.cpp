#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int cnt = a-1 + b-2;
    if (cnt % 2 == 1) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}