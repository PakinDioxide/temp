#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, k;

pair <ll, ll> dvc(int l, int r) {
    if ((r-l+1) < k) return {0, 0};
    int m = (l+r)/2;
    pair <ll, ll> k;
    if ((r-l+1)%2 == 0) k = dvc(l, m);
    else k = dvc(l, m-1);
    if ((r-l+1)%2 == 0) k = {2*k.first + k.second*(m), 2*k.second};
    else k = {2*k.first + k.second*(m) + m, 2*k.second+1};
    return k;
}

void solve() {
    cin >> n >> k;
    cout << dvc(1, n).first << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}