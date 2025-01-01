#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n], idx = 1;
    for (int i = k-1; i >= 0; i--) {
        for (int j = i; j < n; j += k) a[j] = idx++;
    }
    for (int i : a) cout << i << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}