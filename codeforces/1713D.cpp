#include <bits/stdc++.h>
#define ll long long

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin >> n;
    vector <int> a;
    for (int i = 1; i <= (1 << n); i++) a.emplace_back(i);
    shuffle(a.begin(), a.end(), rng);
    while (a.size() > 1) {
        vector <int> b;
        for (int i = 0; i < (int) a.size(); i += 2) {
            if (i+1 == a.size()) { b.emplace_back(a[i]); continue; }
            cout << "? " << a[i] << ' ' << a[i+1] << endl;
            int x; cin >> x;
            if (x == 1) b.emplace_back(a[i]);
            else if (x == 2) b.emplace_back(a[i+1]);
        }
        a = b;
        shuffle(a.begin(), a.end(), rng);
    }
    cout << "! " << a[0] << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

