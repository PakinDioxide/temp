/*
    author  : PakinDioxide
    created : 17/04/2025 20:16
    task    : 1072
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll q;
    cin >> q;
    for (ll i = 1; i <= q; i++) {
        if (i == 1) cout << 0 << '\n';
        else cout << (i*i*(i*i-1)/2) - (i-2)*(i-1)*4 << '\n';
    }
}