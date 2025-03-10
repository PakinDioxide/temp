#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    int a[n], sum = 0;
    for (auto &e : a) cin >> e, sum += e;
    if ((float) sum/n == (float) x) cout << "YES\n";
    else cout << "NO\n";

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}