#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    if (n == 2) { cout << -1 << '\n'; return; }
    if (n == 3) { cout << "1 3\n2 3\n"; return; }
    if (n == 4) { cout << "1 2\n1 3\n1 4\n"; return; }
    if (n == 5) { cout << "5 2\n 4 1\n 3 1\n 2 4\n"; return; }
    int c[n+2]; for (int i = 2; i <= n; i++) c[i] = 1;
    ll cc = n*(n+1)/2 - 1, ccc = 1;
    while (ccc*ccc < cc) ccc++;
    ll df = ccc*ccc - cc;
    c[df]++;
    for (int i = 2; i <= n; i++) cout << i << ' ' << c[i] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    void solve();
}

/*
n(n+1)/2

5

5 2
4 1
3 1
2 1

6

6 1
5 2
4 1
3 1
2 1

7

7 1
6 1
5 2
4 1
3 2
2 1

8

8 1
7 1
6 1
5 1
4 1
3 1
2 1

9

9 1
8 1
7 1
6 1
5 1
4 1
3 2
2 1

10

10 2
9 1
8 1
7 1
6 1
5 1
4 1
3 1
2 1
*/