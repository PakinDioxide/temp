/*
    author  : PakinDioxide
    created : 29/05/2025 23:50
    task    : 2190
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

#define P complex <double>
#define x real()
#define y imag()

double cross(P a, P b) { return (conj(a)*b).y; }
int col(P a, P b, P c) { double k = cross(b-a, b-c); return (k > 0) - (k < 0); }
bool quick_check(P a, P b, P c, P d) {
    double x1, x2, x3, x4, y1, y2, y3, y4;
    x1 = min(a.x, b.x), y1 = min(a.y, b.y);
    x2 = max(a.x, b.x), y2 = max(a.y, b.y);
    x3 = min(c.x, d.x), y3 = min(c.y, d.y);
    x4 = max(c.x, d.x), y4 = max(c.y, d.y);
    return !(x2 < x3 || x4 < x1 || y2 < y3 || y4 < y1);
}

int solve() {
    P a[4];
    for (auto &e : a) { double X, Y; cin >> X >> Y; e = P(X, Y); }
    return (quick_check(a[0], a[1], a[2], a[3]) && (col(a[0], a[2], a[1])*col(a[0], a[3], a[1]) <= 0 && col(a[2], a[0], a[3])*col(a[2], a[1], a[3]) <= 0));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) cout << (solve() ? "YES\n" : "NO\n");
}