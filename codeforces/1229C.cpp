/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double

using namespace std;

#define P complex <db>
#define x real()
#define y imag()

db cross(P a, P b) { return (conj(a)*b).y; }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    P a[n+1];
    a[0] = P(0, 0);
    for (int i = 1; i <= n; i++) { ll k; cin >> k; a[i] = P(i, a[i-1].y+k); }
    vector <P> ch; int sz = 0;
    for (int i = 0; i <= n; i++) {
        while (sz > 1 && cross(ch[sz-1]-ch[sz-2], a[i]-ch[sz-1]) <= 0) ch.pop_back(), sz--;
        sz++, ch.emplace_back(a[i]);
    }
    for (int i = 0; i < sz-1; i++) {
        ld val = (ch[i+1].y - ch[i].y)/(ch[i+1].x - ch[i].x);
        for (int j = ch[i].x+1; j <= ch[i+1].x; j++) if (j > 0) cout << fixed << setprecision(9) << val << '\n';
    }
}

