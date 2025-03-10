#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    for (auto &e : a) cin >> e;
    string x[n], y[n];
    for (auto &e : x) cin >> e;
    for (int o = 0; o < 3; o++) {
        for (int i = 0; i < n; i++) y[i] = x[a[i]-1];
        for (int i = 0; i < n; i++) x[i] = y[i];
    }
    for (int i = 0; i < n; i++) cout << x[i] << '\n';
}