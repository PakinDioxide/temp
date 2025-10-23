/*
    author  : 
    created : 10/08/2025 22:36
    task    : 2131F
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    string x, y; cin >> x >> y;
    int a[n+1], b[n+1];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) a[i+1] = a[i] + x[i] - '0', b[i+1] = b[i] + y[i] - '0';
    

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}