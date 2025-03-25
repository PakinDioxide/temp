/*
    author  : PakinDioxide
    created : 20/03/2025 14:09
    task    : 2183
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll a[n], k = 0;
    for (auto &e : a) cin >> e, k += e;
    
    cout << k+1 << '\n';
}