/*
    author  : PakinDioxide
    created : 14/04/2025 18:57
    task    : d
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
let x be sth

nx = (x+k) that x+k mod k = 0;

then x must mod k = 0;

nnx = (nx+k+1) that (nx+k+1) mod (k+1) = 0;

so nx mod (k+1) == 0
so x + k mod (k+1) == 0
so x-1 + (k+1) mod (k+1) == 0
so x-1 mod (k+1) = 0

nnnx = (nnx+k+2) that (nnx+k+2) mod (k+2) == 0;

so nnx mod k+2 == 0
so nx+k+1 mod k+2 == 0
so nx-1+k+2 mod k+2 == 0
so nx-1 mod k+2 == 0
so x+k-1 mod k+2 == 0
so x-3+k+2 mod k+2 == 0
so x-3 mod k+2 == 0

conclusion
x mod k == 0
x-1 mod k+1 == 0
x-3 mod k+2 == 0

right?

so we want to find some x, k that maximize n that
for all i in [0, n) (x-(1+2+..+i)) mod (k+i) == 0
and l <= x + k + (k+1) + .. + (k+n-1) <= r

max1≤i≤q(ri) − min1≤i≤q(li) < 10^6

so we should solve each x, k in o(1) time

how do we find the optimal k for each x

how to find the k


*/