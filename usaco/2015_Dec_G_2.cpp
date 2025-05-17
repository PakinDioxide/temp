#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    int t, a, b;
    cin >> t >> a >> b;
    vector <bool> V(t+1);
    V[0] = 1;
    for (int i = a; i <= t; i++) V[i] = max(V[i], V[i-a]);
    for (int i = b; i <= t; i++) V[i] = max(V[i], V[i-b]);
    for (int i = 0; i <= t; i++) V[i/2] = max(V[i/2], V[i]);
    for (int i = a; i <= t; i++) V[i] = max(V[i], V[i-a]);
    for (int i = b; i <= t; i++) V[i] = max(V[i], V[i-b]);
    for (int i = t; i >= 0; i--) if (V[i]) {cout << i << '\n'; return 0;}
}