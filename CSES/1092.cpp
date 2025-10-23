/*
    author  : 
    created : 25/06/2025 18:06
    task    : 1092
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n; cin >> n;
    ll k = n*(n+1)/2;
    if (k % 2 == 1) { cout << "NO\n"; return 0; }
    vector <int> a, b; ll sa = 0;
    for (int i = n; i > 0; i--) {
        if (sa + i <= k/2) a.emplace_back(i), sa += i;
        else b.emplace_back(i);
    }
    if (sa != k/2) { cout << "NO\n"; return 0; }
    cout << "YES\n";
    cout << a.size() << '\n';
    for (auto &e : a) cout << e << ' '; cout << '\n';
    cout << b.size() << '\n';
    for (auto &e : b) cout << e << ' '; cout << '\n';
}