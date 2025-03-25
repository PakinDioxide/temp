/*
    author  : PakinDioxide
    created : 14/03/2025 10:57
    task    : 1826D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    ll a[n+1];
    for (int i = 0; i < n; i++) cin >> a[i+1];
    ll l[n+1], r[n+2], ans = LLONG_MIN;
    l[0] = r[n+1] = INT_MIN;
    for (int i = 1; i <= n; i++) l[i] = max(l[i-1], a[i] + i);
    for (int i = n; i > 0; i--) r[i] = max(r[i+1], a[i] - i);
    for (int i = 2; i < n; i++) ans = max(ans, a[i] + l[i-1] + r[i+1]);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
H1 : What can we say about the position of the maximum elements relative to [l,r]?
    let a, b, c be the index of the three maximums
    l must equal to a, r must equal to c

    
*/