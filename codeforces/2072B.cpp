#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll a = 0, b = 0;
    for (int i = 0; i < n; i++) a += (s[i] == '-'), b += (s[i] == '_');
    if (a < 2 || b < 1) {cout << 0 << '\n'; return;}
    cout << (ll)(a/2)*(a/2+a%2)*b << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}