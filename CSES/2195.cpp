/*
    author  : 
    created : 25/06/2025 20:01
    task    : 2195
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

#define P complex <ll>
#define x real()
#define y imag()

double cross(P a, P b) { return (conj(a)*b).y; }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    P a[n];
    for (auto &e : a) { ll X, Y; cin >> X >> Y; e = {X, Y}; }
    sort(a, a+n, [&] (const P &p, const P &q) {
        return (p.x < q.x ? 1 : p.x == q.x ? p.y < q.y : 0);
    });
    vector <P> ch;
    for (int i = 0; i < n; i++) {
        while (ch.size() > 1 && cross(ch[ch.size()-1] - ch[ch.size()-2], a[i] - ch[ch.size()-1]) < 0) ch.pop_back();
        ch.emplace_back(a[i]);
    }
    int l = ch.size();
    for (int i = n-2; i >= 0; i--) {
        while (ch.size() > l && cross(ch[ch.size()-1] - ch[ch.size()-2], a[i] - ch[ch.size()-1]) < 0) ch.pop_back();
        ch.emplace_back(a[i]);
    }
    ch.pop_back();
    cout << ch.size() << '\n';
    for (auto &e : ch) cout << e.x << ' ' << e.y << '\n';
}