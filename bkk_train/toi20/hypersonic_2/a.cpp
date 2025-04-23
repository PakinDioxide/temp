/*
    author  : PakinDioxide
    created : 11/04/2025 17:26
    task    : a
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll lcm(ll x, ll y) { return x * y / __gcd(x , y); }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll a[n];
    for (auto &e : a) cin >> e;
    for (int i = 0; i < n-1; i++) a[i+1] = lcm(a[i], a[i+1]);
    cout << a[n-1] << '\n';
}