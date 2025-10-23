#include <bits/stdc++.h>
#define ll long long

using namespace std;

int ask(int l, int r, int k) {
    cout << k << ' ' << l << ' ' << r << endl;
    int x; cin >> x;
    return x;
}

void solve() {
    int n; cin >> n;
    int l = 1, r = n, x1 = 1;
    while (l <= r) {
        int x = l + (r-l)/2;
        if (ask(1, x, 1) != ask(1, x, 2)) x1 = x, r = x-1;
        else l = x+1;
    }
    int c = abs(ask(1, n, 1) - ask(1, n, 2));
    cout << "! " << x1 << ' ' << x1 + c - 1 << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    void solve();
}