/*
    author  : PakinDioxide
    created : 11/04/2025 10:02
    task    : 863B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int a[2*n];
    for (auto &e : a) cin >> e;
    sort(a, a+2*n);
    int mn = INT_MAX, s = 0;
    for (int i = 1; i < 2*n-1; i += 2) s += a[i+1] - a[i];
    mn = min(mn, s);
    s = 0;
    for (int i = 0; i < 2*n-2; i += 2) s += a[i+1] - a[i];
    mn = min(mn, s);
    s = 0;
    for (int i = 2; i < 2*n; i += 2) s += a[i+1] - a[i];
    mn = min(mn, s);
    cout << mn << '\n';
}