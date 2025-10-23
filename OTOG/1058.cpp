/*
    author  : PakinDioxide
    created : 13/07/2025 23:36
    task    : 1058
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, q, sz = 0, it = 0;
ll w[mxN], c[mxN], p[mxN], ans[mxN];
vector <tuple <int, int, int, int>> Q;
deque <int> cht;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++) cin >> w[i], w[i] += w[i-1];
    for (int i = 1; i <= n; i++) cin >> c[i], p[i] = p[i-1] + c[i] * (w[i] - w[i-1]);
    for (int i = 0; i < q; i++) { int x, y; cin >> x >> y; x++, y++; Q.emplace_back(min(x, y), x, y, i); }
    sort(Q.begin(), Q.end());
    auto calc = [&] (ll x, int j) { return -c[j]*x + (-p[j] - c[j]*w[j]); };
    auto m = [&] (int x, int y) { return (double) (calc(0, x) - calc(0, y)) / ((-c[y]) - (-c[x])); };
    for (int i = 1; i <= n; i++) {
        while (sz > 0 && (-c[cht[sz-1]]) == (-c[i]) && calc(0, cht[sz-1]) >= calc(0, i)) cht.pop_back(), sz--;
        while (sz > 1 && m(cht[sz-1], i) <= m(cht[sz-1], cht[sz-2])) cht.pop_back(), sz--;
        cht.emplace_back(i), sz++;
        while (it < q && get<0>(Q[it]) == i) {
            auto [tmp, x, y, id] = Q[it++];
            int l = 0, r = sz-2, idx = sz-1;
            while (l <= r) {
                int mid = l + (r-l)/2;
                if (m(cht[mid], cht[mid+1]) <= -w[y]) l = mid+1;
                else r = mid-1, idx = mid;
            }
            ans[id] = p[x] + calc(-w[y], cht[idx]);
        }
    }
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}

/*
start at x, want to arrive at y
p[i] = p[i-1] + c[i] * w[i] (dist from i-1 to i)
ans = min j <= min(x, y) (p[x] - p[j] + c[j]*(w[y] - w[j]))
    = p[x] + min (c[j]*(w[y]) + (-p[j] - c[j]*w[j]))
*/