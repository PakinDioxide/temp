#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int N; cin >> N;
    ll A[N]; for (auto &e : A) cin >> e;
    ll ans = 0;
    for (int i = 0; i < N-2; i++) ans += A[i];
    ans += A[N-1] - A[N-2];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

