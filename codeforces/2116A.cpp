/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;

void solve() {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    if (min(a, c) >= min(b, d)) cout << "Gellyfish\n";
    else cout << "Flower\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

