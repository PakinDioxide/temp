#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; ll k; cin >> n >> k;
    int tp[n+1];
    ll P[n+1];
    P[0] = 0;
    vector <ll> C;
    C.emplace_back(0), C.emplace_back(k), C.emplace_back(-k);
    for (int i = 1; i <= n; i++) cin >> tp[i];
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        if (tp[i] == 1) P[i] = P[i-1] + x;
        else P[i] = P[i-1] - x;
        C.emplace_back(P[i]);
        C.emplace_back(P[i]+k);
        C.emplace_back(P[i]-k);
    }
    sort(C.begin(), C.end());
    C.resize(unique(C.begin(), C.end()) - C.begin());
    ll Pr[n+1], Pn[n+1];
    for (int i = 0; i <= n; i++) {
        Pr[i] = upper_bound(C.begin(), C.end(), P[i] - k) - C.begin();
        Pn[i] = upper_bound(C.begin(), C.end(), P[i] + k) - C.begin();
        P[i] = upper_bound(C.begin(), C.end(), P[i]) - C.begin();
    }
    int q; cin >> q;
    vector <tuple <int, int, int, int>> Q;
    int sqT = ceil(sqrt(n));
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r; l--;
        Q.emplace_back(l/sqT, r, l, i);
    }
    sort(Q.begin(), Q.end());
    int L = 0, R = -1;
    ll cnt = 0, ans[q+1];
    int cc[(int) C.size() + 5]; memset(cc, 0, sizeof(cc));
    for (auto &[ii, r, l, idx] : Q) {
        while (R < r) {
            ++R;
            cnt += cc[Pr[R]];
            cc[P[R]]++;
        }
        while (L > l) {
            --L;
            cnt += cc[Pn[L]];
            cc[P[L]]++;
        }
        while (L < l) {
            cc[P[L]]--;
            cnt -= cc[Pn[L]];
            L++;
        }
        while (R > r) {
            cc[P[R]]--;
            cnt -= cc[Pr[R]];
            R--;
        }
        ans[idx] = cnt;
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}

