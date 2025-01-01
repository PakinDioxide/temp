// PakinDioxide SUB3
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll sum = 0, b[n+1];
    for (int i = 1; i <= n; i++) cin >> b[i], sum += b[i];
    for (int i = 0; i < n-1; i++) {int x, y; cin >> x >> y;}
    for (int i = 0; i < n; i++) cout << sum << ' ';
}