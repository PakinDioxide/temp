#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("shell.in", "r", stdin);

    int n;

    cin >> n;

    int lo[3];
    lo[0] = 1;
    lo[1] = 2;
    lo[2] = 3;

    int sc[3];
    sc[0] = sc[1] = sc[2] = 0;

    for (int i = 0; i < n; i++) {
        int a, b, g;

        cin >> a >> b >> g;

        for (int i = 0; i < 3; i++) {
            if (lo[i] == a) {
                lo[i] = b;
            } else if (lo[i] == b) {
                lo[i] = a;
            }

            if (lo[i] == g) sc[i]++;
        }
    }

    freopen("shell.out", "w", stdout);

    cout << max({sc[0], sc[1], sc[2]});
}
