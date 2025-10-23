/*
    author  : PakinDioxide
    created : 01/04/2025 20:02
    task    : 682
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll sum = 0, n;
    cin >> n;
    string k = to_string(n);
    for (auto &e : k) sum += (e-'0');
    if (sum % n == 0) cout << "YES\n";
    else cout << "NO\n";
}