#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 5e5+5;

int n, q;
ll k, a[mxN], p[mxN], ans[mxN], val[mxN];

struct node {
    vector <int> v;
    multiset <pair <int, int>> a;
};

// vector <node> idk(15), tmp(15);
map <int, node> idk, tmp;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q >> k;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i-1];
        cin >> a[i];
        if (i % 2 == 0) { a[i] = -a[i]; continue; }
        p[i] += a[i] / k;
        a[i] %= k;
    }
    int it = 0;
    vector <tuple <int, int, int>> Q(q);
    for (auto &[r, l, id] : Q) cin >> l >> r, id = it++;
    sort(Q.begin(), Q.end());
    vector <pair <int, int>> v;
    it = 0;
    for (auto &[r, l, id] : Q) {
        while (it < r) {
            ++it;
            vector <int> g(k);
            for (auto &[i, iiii] : idk) {
                if (a[it] > 0) {
                    ll nw = i + a[it];
                    if (nw >= k) idk[i].v.emplace_back(it);
                    nw %= k;
                    g[i] = nw;
                } else {
                    ll nw = (i + a[it]);
                    nw = max(nw, 0LL);
                    g[i] = nw;
                }
                if (tmp[g[i]].a.size() < idk[i].a.size()) swap(tmp[g[i]], idk[i]);
                for (auto &[x, y] : idk[i].a) {
                    if (idk[i].v.size()) {
                        int itt = upper_bound(idk[i].v.begin(), idk[i].v.end(), y) - idk[i].v.begin();
                        val[x] += (int) idk[i].v.size() - itt;
                    }
                    tmp[g[i]].a.emplace(x, it);
                }
            }
            // for (int i = 0; i < k; i++) idk[i].v.clear(), idk[i].a.clear();
            idk.clear();
            swap(tmp, idk);
            if (a[it] > 0) idk[a[it]].a.emplace(it, it);
            else idk[0].a.emplace(it, it);
            /*
            cout << "# " << it << '\n';
            for (int i = 0; i < k; i++) {
                cout << "- " << i << " : ";
                for (auto &[x, y] : idk[i].a) cout << x << ' ';
                cout << '\n';
            }
            */
        }
        int CNT = 0, idx = -1;
        for (auto &[i, iiii] : idk) if (idk[i].a.size()) {
            auto [x, y] = (*idk[i].a.upper_bound(make_pair(l, INT_MIN)));
            if (x == l) {
                idx = i;
                int itt = upper_bound(idk[i].v.begin(), idk[i].v.end(), y) - idk[i].v.begin();
                CNT = (int) idk[i].v.size() - itt;
                break;
            }
        }
        assert(idx != -1);
        ans[id] = p[r] - p[l-1] + val[l] + CNT;
    }
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}
