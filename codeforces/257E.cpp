#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

const int mxN = 1e5+5;

int n, m, fen[mxN][2];

void upd(int idx, int x, int k) { idx = k == 0 ? idx : m-idx+1; for (int i = idx; i <= m; i += i & -i) fen[i][k] += x; }
int qr(int idx, int k) { idx = k == 0 ? idx : m-idx+1; int x = 0; for (int i = idx; i > 0; i -= i & -i) x += fen[i][k]; return x; }

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    tuple <int, pair <int, int>, int> a[n];
    int iii = 0;
    for (auto &[x, y, ittt] : a) cin >> x >> y.first >> y.second, ittt = iii++;
    sort(a, a+n);
    set <pair <int, int>> s;
    int t = 0, l = 1, ans[n], w[n]; memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; i++) {
        // cout << i << " : " << l << '\n';
        int x = get<0>(a[i]), L = get<1>(a[i]).first, r = get<1>(a[i]).second, ittt = get<2>(a[i]);
        t = x;
        upd(L, 1, 0); upd(L, 1, 1);
        s.emplace(L, -ittt-1); w[ittt] = r;
        int tt = LLONG_MAX; if (i < n-1) tt = get<0>(a[i+1]);
        while (1) {
            if (s.empty()) break;
            int X = qr(l, 0), Y = qr(l, 1);
            if (X > Y) {
                // cout << i << ' ' << "L " << l << ' ' << t << '\n';
                auto it = prev(s.lower_bound(make_pair(l, LLONG_MAX)));
                if (l - (*it).first + t <= tt) {
                    t += l - (*it).first; l = (*it).first;
                    while ((*it).first == l) {
                        if ((*it).second < 0) {
                            int idx = -(*it).second-1;
                            upd(l, -1, 0); upd(l, -1, 1);
                            s.erase(it);
                            s.emplace(w[idx], idx);
                            upd(w[idx], 1, 0); upd(w[idx], 1, 1);
                        } else {
                            ans[(*it).second] = t; 
                            upd(l, -1, 0); upd(l, -1, 1);
                            s.erase(it);
                        }
                        if (s.empty()) break;
                        it = s.lower_bound(make_pair(l, LLONG_MAX));
                        if (it == s.begin()) break;
                        it = prev(it);
                    }
                } else {l -= (tt - t); break;}
            } else if (X <= Y && Y != 0) {
                // cout << i << ' ' << "L " << l << ' ' << t << '\n';
                auto it = s.lower_bound(make_pair(l, INT_MIN));
                if ((*it).first + t - l <= tt) {
                    t += (*it).first - l; l = (*it).first;
                    while ((*it).first == l) {
                        if ((*it).second < 0) {
                            int idx = -(*it).second-1;
                            upd(l, -1, 0); upd(l, -1, 1);
                            s.erase(it);
                            s.emplace(w[idx], idx);
                            upd(w[idx], 1, 0); upd(w[idx], 1, 1);
                        } else {
                            ans[(*it).second] = t;
                            upd(l, -1, 0); upd(l, -1, 1);
                            s.erase(it);
                        }
                        if (s.empty()) break;
                        it = s.lower_bound(make_pair(l, INT_MIN));
                        if (it == s.end()) break;
                    }
                } else {l += (tt - t); break;}
            } else break;
            // cerr << "AR";
        }
    }
    for (auto &e : ans) cout << e << '\n';
}