#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (auto &e : a) cin >> e;
    cout << "? 1 2\n";
    cout.flush();
    int p, q;
    cin >> p;
    cout << "? 2 1\n";
    cout.flush();
    cin >> q;
    cout << "! " << (p == q ? 'B' : 'A') << '\n';
    cout.flush();
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}