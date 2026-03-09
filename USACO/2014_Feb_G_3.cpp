#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int N;
pair <int, ll> A[mxN];
ll ST[mxN], EN[mxN], FW[mxN];

void UPD(int idx, ll x) { for (int i = idx; i <= N; i += i & -i) FW[i] = max(FW[i], x); }
ll QR(int idx) { ll x = 0; for (int i = idx; i > 0; i -= i & -i) x = max(x, FW[i]); return x; }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // freopen("boarding.in", "r", stdin);
    // freopen("boarding.out", "w", stdout);
    cin >> N;
    for (int i = N; i >= 1; i--) cin >> A[i].first >> A[i].second;
    for (int i = 1; i <= N; i++) {
        auto &[S, T] = A[i];
        ST[i] = max((ll) S + i - 1, QR(N) - (N - S) + i);
        EN[i] = ST[i] + T;
        UPD(S, EN[i] + N - S - i);
        cout << ST[i] << ' ' << EN[i] << '\n';
    }
    ll ANS = 0;
    for (int i = 1; i <= N; i++) ANS = max(ANS, EN[i]);
    cout << ANS << '\n';
}

