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

void solve() {
    int n; cin >> n;
    int a[n];
    int l = 0, r = n-1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) a[l++] = i+1;
        else a[r--] = i+1;
    }
    for (auto &e : a) cout << e << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

