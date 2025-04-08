/*
    author  : PakinDioxide
    created : 20/03/2025 19:07
    task    : B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n];
    for (auto &e : a) cin >> e;
    sort(a, a+n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {cnt += a[i]; if (cnt > k) {cout << i << '\n'; return 0;}}
    cout << n << '\n';
}