/*
    author  : PakinDioxide
    created : 29/05/2025 23:28
    task    : 2189
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

#define P complex <double>
#define x real()
#define y imag()

double cross(P a, P b) { return (conj(a)*b).y; }

void solve() {
    P a[3];
    for (auto &e : a) { double X, Y; cin >> X >> Y; e = {X, Y}; }
    double c = cross(a[2]-a[0], a[2]-a[1]);
    if (c > 0) cout << "LEFT\n";
    else if (c == 0) cout << "TOUCH\n";
    else cout << "RIGHT\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}