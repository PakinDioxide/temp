#include <bits/stdc++.h>
#define ll long long

using namespace std;

int ask(int i, int j) {
    int k;
    cout << "? " << i << ' ' << j << endl;
    cin >> k;
    return k;
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= 2*n-2; i += 2) {
        cout << "? " << i << ' ' << i+1 << endl;
        int k; cin >> k;
        if (k == 1) {
            cout << "! " << i << endl;
            return;
        }
    }
    int P = ask(1, 2*n-1), Q = ask(2, 2*n-1);
    if (P == 1 || Q == 1) {
        cout << "! " << 2*n-1 << endl;
    } else {
        cout << "! " << 2*n << endl;
    }

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

