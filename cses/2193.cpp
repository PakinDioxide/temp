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

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    P a[n+1];
    for (int i = 0; i < n; i++) { ll X, Y; cin >> X >> Y; a[i] = P(X, Y); }
    a[n] = a[0];
    ll A = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        A += (conj(a[i])*a[i+1]).y;
        cnt += __gcd(abs(a[i].x-a[i+1].x), abs(a[i].y-a[i+1].y));
    }
    cout << (abs(A)-cnt)/2+1 << ' ' << cnt << '\n';
}

