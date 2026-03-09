#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int P, n; cin >> P >> n;
    if (P == 1) {
        cout << n-1 << endl;
        for (int i = 1; i < n; i++) {
            int x; cin >> x;
            cout << i << endl;
        }
    } else {
        int a[n];
        for (auto &e : a) cin >> e;
        int id[n]; fill(id, id+n, -1);
        for (int i = 0; i < n; i++) {
            if (id[a[i]] == -1) id[a[i]] = i;
            else {
                cout << id[a[i]] << ' ' << i << endl;
                return 0;
            }
        }
    }
}
