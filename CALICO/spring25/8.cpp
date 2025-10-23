/*
    author  : PakinDioxide
    created : 27/04/2025 08:29
    task    : 8
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n;
    cin >> n;
    ll k = 0, l = 0, r = n;
    while (l <= r) {
        ll x = l + (r-l)/2;
        if (x*(x+1)/2 <= n) k = x, r = x-1;
        else l = x+1;
    }
    if (k*(k+1)/2 < n) k++;
    ll d = n-(k*(k+1))/2;
    
}

/*
n*(n+1)/2 <= n
*/

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}