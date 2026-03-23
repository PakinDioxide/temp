#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n; ll k; cin >> n >> k;
    ll h[n], c[n];
    for (int i = 0; i < n; i++) cin >> h[i] >> c[i];
    cout << c[0] * (n-1) << '\n';
}
