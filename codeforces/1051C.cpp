#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    int a[n], c[105]; memset(c, 0, sizeof(c));
    for (auto &e : a) cin >> e, c[e]++;
    int cc = 0, ccc = 0;
    for (auto &e : a) {
        if (c[e] == 1) cc++;
        else if (c[e] > 2) ccc++;
    }
    if (cc % 2 == 1 && ccc == 0) { cout << "NO\n"; return 0; }
    int t = 0;
    if (cc % 2 == 0) {
        cout << "YES\n";
        for (auto &e : a) {
            if (c[e] > 1) cout << 'A';
            else cout << (char) ('A' + (t % 2)), t++;
        }
        cout << '\n';
    } else {
        int idx;
        for (auto &e : a) if (c[e] > 2) idx = e;
        cout << "YES\n";
        for (auto &e : a) {
            if (e == idx) cout << 'B', idx = -1;
            else if (c[e] > 1) cout << 'A';
            else cout << (char) ('A' + (t % 2)), t++;
        }
        cout << '\n';
    }
}