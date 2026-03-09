#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    // can only move right
    int N; cin >> N;
    ll A[N]; for (auto &e : A) cin >> e;
    ll L = 0, R = 1e18, ans = -1;
    while (L <= R) {
        ll x = L + (R-L)/2;
        ll c = 0, ok = 1;
        for (auto &e : A) {
            c += e-x;
            if (c < 0) { ok = 0; break; }
        }
        if (ok) ans = x, L = x+1;
        else R = x-1;
    }
    vector <int> v;
    ll LF[N]; memset(LF, 0, sizeof(LF));
    for (int i = 0; i < N; i++) {
        if (A[i] < ans) {
            ll k = ans - A[i];
            while (k > 0) {
                if (LF[v.back()] >= k) LF[v.back()] -= k, k = 0;
                else k -= LF[v.back()], LF[v.back()] = 0, v.pop_back();
            }
        } else LF[i] = A[i] - ans, v.emplace_back(i);
    }
    ll f = 0, mx = ans;
    for (int i = N-1; i >= 0; i--) {
        f += mx - ans;
        if (LF[i] >= f) LF[i] -= f, f = 0;
        else f -= LF[i], LF[i] = 0;
        if (LF[i] > 0) {
            mx += ceil((double) LF[i] / (N - i));
            f += ((N - i) - (LF[i] % (N - i))) % (N - i);
        }
    }
    cout << mx - ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

