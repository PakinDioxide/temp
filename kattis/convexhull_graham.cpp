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

int col(P a, P b, P q) {
    db k = cross(q-a, q-b);
    return (k > 0) - (k < 0);
}

bool comp(const P &a, const P &b) {
    return (a.y < b.y ? 1 : a.y == b.y ? a.x > b.x : 0);
}

void solve() {
    int n; cin >> n; if (n == 0) exit(0);
    vector <P> a(n);
    for (int i = 0; i < n; i++) {
        db X, Y; cin >> X >> Y;
        a[i] = P{X, Y};
    }
    sort(a.begin(), a.end(), comp);
    a.resize(unique(a.begin(), a.end()) - a.begin());
    n = a.size();
    tuple <db, db, int> v[n-1];
    for (int i = 1; i < n; i++) v[i-1] = make_tuple(atan2(a[i].y-a[0].y, a[i].x-a[0].x), norm(a[i]-a[0]), i);
    sort(v, v+n-1);
    vector <P> ch;
    ch.emplace_back(a[0]);
    for (auto &E : v) {
        P e = a[get<2>(E)];
        while (ch.size() > 1 && col(ch[ch.size()-2], e, ch[ch.size()-1]) != -1) ch.pop_back();
        ch.emplace_back(e);
    }
    cout << ch.size() << '\n';
    for (auto &e : ch) cout << e.x << ' ' << e.y << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while (1) solve();
}

