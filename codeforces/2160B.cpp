#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    ll b[n]; for (auto &e : b) cin >> e;
    ll a[n];
    a[0] = 1;
    for (int i = 1; i < n; i++) {
        int d = b[i] - b[i-1];
        if (d > i) a[i] = i+1;
        else a[i] = a[i-d];
    }
    for (auto &e : a) cout << e << ' '; cout << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}

/*
1 2 3
1 2 1
1 2 2
1 1 1 2
*/