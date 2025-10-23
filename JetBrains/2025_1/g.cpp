#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    vector <int> a(n); for (auto &e : a) cin >> e;
    if (a[n-1] == 1) { cout << "NO\n"; return; }
    if (n == 1) {
        cout << "YES\n0\n";
        return;
    } else if (n == 2) {
        if (a[0] == 1) cout << "YES\n(1->0)\n";
        else cout << "NO\n";
        return;
    }
    if (a[n-2] == 0 && a[n-3] == 0) {
        cout << "YES\n";
        if (n > 3) {
            cout << a[0];
            for (int i = 1; i < n-3; i++) cout << "->" << a[i];
            cout << "->(0->0)->0\n";
        } else cout << "(0->0)->0\n";
        return;
    } else if (a[n-2] == 1) {
        cout << "YES\n";
        cout << a[0];
        for (int i = 1; i < n-2; i++) cout << "->" << a[i];
        cout << "->1->0\n";
        return;
    } else {
        int idx = -1;
        for (int i = n-3; i >= 0; i--) if (a[i] == 0) { idx = i; break; }
        if (idx == -1) { cout << "NO\n"; return; }
        cout << "YES\n";
        for (int i = 0; i < idx; i++) cout << a[i] << "->";
        cout << "(0->(1";
        for (int i = idx+2; i <= n-2; i++) cout << "->" << a[i];
        cout << "))->0\n";
        return;
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // int t; cin >> t;
    int t = 1;
    while (t--) solve();
}
