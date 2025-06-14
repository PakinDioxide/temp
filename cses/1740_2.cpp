/*
    author  : PakinDioxide
    created : 22/05/2025 00:02
    task    : 1740_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

struct T {
    int x, y1, y2, k;
    bool operator<(const T &o) const {
        return x < o.x;
    }
};

int n;
ll fen[2*mxN], ans = 0;
vector <int> cmp;
vector <T> v;

void upd(int idx, ll x) { for (int i = idx; i <= 2*n; i += i & -i) fen[i] += x; }
int qr(int idx) { ll x = 0; for (int i = idx; i > 0; i -= i & -i) x += fen[i]; return x; }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        v.emplace_back(T{x1, y1, y2, 1});
        if (y1 == y2) v.emplace_back(T{x2, y1, y2, -1});
        cmp.emplace_back(y1), cmp.emplace_back(y2);
    }
    sort(v.begin(), v.end());
    sort(cmp.begin(), cmp.end());
    for (auto &e : v) {
        e.y1 = upper_bound(cmp.begin(), cmp.end(), e.y1) - cmp.begin(), e.y2 = upper_bound(cmp.begin(), cmp.end(), e.y2) - cmp.begin();
        if (e.y1 == e.y2) upd(e.y1, e.k);
        else ans += qr(e.y2) - qr(e.y1-1);
    }
    cout << ans << '\n';
}