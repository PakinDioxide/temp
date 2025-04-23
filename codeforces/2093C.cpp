/*
    author  : PakinDioxide
    created : 08/04/2025 21:46
    task    : 2093C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int is_prime(int x) {
    if (x < 2) return 0;
    if (x == 2) return 1;
    for (int i = 2; i <= sqrt(x); i++) if (x % i == 0) return 0;
    return 1;
}

void solve() {
    string s;
    ll x, k;
    cin >> s >> k;
    x = stoi(s);
    if (k == 1) {
        if (is_prime(x)) cout << "YES\n";
        else cout << "NO\n";
    } else {
        if (s.size() > 1) cout << "NO\n";
        else {
            ll kk = 0;
            for (int i = 0; i < k; i++) kk = (kk*10)+x;
            if (is_prime(kk)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}