#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, k = 5, idx = 1;
    cin >> n;
    while (n > k) k*=5, idx++;
    cout << "MIT";
    if (idx > 1) cout << '^' << idx;
    cout << " time\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}