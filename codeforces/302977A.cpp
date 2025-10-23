#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll n; cin >> n;
    if (n % 2 == 1) cout << 0 << '\n';
    else cout << (1 << (n >> 1)) << '\n';
}