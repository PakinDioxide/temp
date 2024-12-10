#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    int n, q;

    cin >> n >> q;

    vector <int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < q; i++) {
        int x, y;

        cin >> x >> y;

        if (x > y) swap(x, y);

        int n1 = lower_bound(a.begin(), a.end(), x) - a.begin(), n2 = lower_bound(a.begin(), a.end(), y) - a.begin();

        if (n1 < n && n2 < n && a[n2] == y) n2++;

        cout << n2-n1 << "\n";
    }
}
