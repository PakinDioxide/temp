#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int N; cin >> N;
    ll A[N]; for (auto &e : A) cin >> e;
    ll G = A[0];
    for (auto &e : A) G = __gcd(G, e);
    for (auto &e : A) e /= G;
    sort(A, A+N);
    ll g = A[0];
    ll ans = g;
    for (int i = 1; i < N; i++) {
        ll mn = LLONG_MAX;
        for (int j = i; j < N; j++) mn = min(mn, A[j]);
        g = __gcd(g, mn);
        ans += g;
        for (int j = i; j < N; j++) if (A[j] == mn) {
            swap(A[i], A[j]);
            break;
        }
        for (int j = i+1; j < N; j++) if (A[j] % mn == 0) A[j] /= mn;
    }
    for (int i = 0; i < N; i++) cout << A[i] << ' '; cout << '\n';
    cout << ans * G << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

