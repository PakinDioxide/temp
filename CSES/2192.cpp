/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;

#define P complex <ll>
#define x real()
#define y imag()

ll cross(P a, P b) { return (conj(a)*b).y; }

int col(P a, P b, P p) {
    ll k = cross(p-a, p-b);
    return (k > 0) - (k < 0);
}

bool on(P a, P b, P p) {
    return (min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y) && !col(a, b, p));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q; cin >> n >> q;
    P a[n+1];
    for (int i = 0; i < n; i++) { ll X, Y; cin >> X >> Y; a[i] = P(X, Y); }
    a[n] = a[0];
    while (q--) {
        ll X, Y; cin >> X >> Y; P u = P(X, Y);
        bool bd = 0; int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (on(a[i], a[i+1], u)) { bd = 1; break; }
            if (a[i].y <= u.y && u.y < a[i+1].y && col(a[i], a[i+1], u) > 0) cnt++;
            if (a[i+1].y <= u.y && u.y < a[i].y && col(a[i+1], a[i], u) > 0) cnt++;
        }
        if (bd) cout << "BOUNDARY\n";
        else if (cnt % 2 == 0) cout << "OUTSIDE\n";
        else cout << "INSIDE\n";
    }
}
/*
4 1
1 1
4 2
3 5
1 4
2 3
*/
