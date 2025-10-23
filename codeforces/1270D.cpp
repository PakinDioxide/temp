#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector <int> v;
    for (int i = 1; i <= k+1; i++) {
        cout << "? ";
        for (int j = 1; j <= k+1; j++) if (i != j) cout << j << ' '; cout << endl;
        int p, q; cin >> p >> q;
        v.emplace_back(q);
    }
    int mx = -1;
    for (auto &e : v) mx = max(mx, e);
    int m = 0;
    for (auto &e : v) m += (e == mx);
    cout << "! " << m << endl;
}