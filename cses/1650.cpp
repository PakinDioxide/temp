#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;

    cin >> n >> q;

    int p[n+1];
    p[n] = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        p[i+1] = p[i] ^ a;
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        a--;

        cout << (p[b] ^ p[a]) << "\n";
    }
}
