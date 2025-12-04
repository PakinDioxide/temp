#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    int a[2*n+1]; memset(a, 0, sizeof(a));
    vector <int> t, tt;
    t.emplace_back(1);
    for (int i = 2; i <= 2*n; i++) {
        t.emplace_back(i);
        cout << "? "; cout << t.size() << ' ';
        for (auto &e : t) cout << e << ' '; cout << endl;
        int x; cin >> x;
        if (x > 0) a[i] = x, t.pop_back(), tt.emplace_back(i);
    }
    for (int i = 1; i <= 2*n; i++) if (a[i] == 0) {
        cout << "? "; cout << tt.size() + 1 << ' ';
        for (auto &e : tt) cout << e << ' ';
        cout << i << endl;
        cin >> a[i];
    }
    cout << "! ";
    for (int i = 1; i <= 2*n; i++) cout << a[i] << ' '; cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}
