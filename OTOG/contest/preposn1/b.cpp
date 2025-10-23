#include <bits/stdc++.h>

using namespace std;

#define int long long

int a[2005][2005];

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        string a, b;
        cin >> a >> b;
        sort(a.begin(), a.end()); sort(b.begin(), b.end());
        if (a==b) cout << "same\n";
        else cout << "not same\n";
    }
}