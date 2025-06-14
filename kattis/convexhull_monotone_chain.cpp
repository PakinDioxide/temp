/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long
#define db double

using namespace std;

#define P complex <db>
#define x real()
#define y imag()

db cross(P a, P b) { return (conj(a)*b).y; }

void solve() {
    int n; cin >> n; if (n == 0) exit(0);
    vector <P> a(n);
    for (auto &e : a) { db X, Y; cin >> X >> Y; e = P(X, Y); }
    sort(a.begin(), a.end(), [&] (const P &a, const P &b) {
        return a.x < b.x ? 1 : a.x == b.x ? a.y < b.y : 0;
    });
    a.resize(unique(a.begin(), a.end()) - a.begin()), n = a.size();
    vector <P> ch; int sz = 0;
    for (int i = 0; i < n; i++) {
        auto e = a[i];
        while (sz > 1 && cross(ch[sz-1]-ch[sz-2], e-ch[sz-1]) <= 0) ch.pop_back(), sz--;
        sz++, ch.emplace_back(e);
    }
    int lw = ch.size();
    for (int i = n-1; i >= 0; i--) {
        auto e = a[i];
        while (sz > lw && cross(ch[sz-1]-ch[sz-2], e-ch[sz-1]) <= 0) ch.pop_back(), sz--;
        sz++, ch.emplace_back(e);
    }
    ch.pop_back(), sz--;
    cout << sz << '\n';
    for (auto &e : ch) cout << e.x << ' ' << e.y << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while (1) solve();
}

