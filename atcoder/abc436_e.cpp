#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    int a[n]; for (auto &e : a) cin >> e;
    ll cnt = 0;
    for (int i = 0; i < n; i++) cnt += (a[i] != (i+1));
    cout << cnt * (cnt-1) / 2 << '\n';
}

