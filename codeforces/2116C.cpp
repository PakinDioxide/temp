/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;

void solve() {
    int n; cin >> n;
    int a[n];
    for (auto &e : a) cin >> e;
    int g = a[0];
    for (auto &e : a) g = __gcd(g, e);
    for (auto &e : a) cout << e/g << ' ';
    cout << '\n';
    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

