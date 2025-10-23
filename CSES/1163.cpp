#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;

    cin >> x >> n;

    set <int> a;

    a.insert(1);
    a.insert(x);

    for (int i = 0; i < n; i++) {
        int q;
        cin >> q;

        a.insert(q);

        int m = 0;

        for (auto j = a.begin(); j != a.end(); ++j) {
            if (*j == 1) continue;
            auto p = prev(j);
            m = max(m, (*j) - (*p));
        }

        cout << m << " ";
    }

}
