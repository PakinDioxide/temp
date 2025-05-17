/*
    author  : PakinDioxide
    created : 02/05/2025 00:35
    task    : a
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll x;
    cin >> x;
    x--;
    cout << (x > 0) + max(0, (int) ceil((x-5)/6.0)) << '\n';
}