/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double

using namespace std;

ll p(pair <ll, ll> x) {
    return x.first * 100 + x.second;
}

void solve() {
    int n, m; cin >> n >> m; swap(n, m);
    pair <ll, ll> a[n];
    for (auto &e : a) { ll k; cin >> k; e.first = k/100, e.second = k % 100; }
    sort(a, a+n);
    for (int i = 0; i < m/2; i++) {
        for (int j = 0; j < 3; j++) cout << p(a[i]) << ' ' << p(a[n-i-1]) << ' ';
        cout << '\n';
        for (int j = 0; j < 3; j++) cout << p(a[n-i-1]) << ' ' << p(a[i]) << ' ';
        cout << '\n';
    }
    if (m % 2 == 1) {for (int j = 0; j < 3; j++) cout << p(a[m/2]) << ' ' << p(a[n-(m/2)-1]) << ' '; cout << '\n';}
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

