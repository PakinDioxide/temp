/*
    author  : PakinDioxide
    created : 28/04/2025 21:47
    task    : 2104C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    int ok = 0;
    if (a[0] == 'A' && a[n-1] == 'A') ok = 1;
    if (a[n-1] == 'A' && a[n-2] == 'A') ok = 1;
    int kk = 1;
    for (int i = 0; i < n-1; i++) kk = min(kk, (int) (a[i] == 'A'));
    if (ok || kk) cout << "Alice\n";
    else cout << "Bob\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
if a player has card 1 and n, then that will instantly win

only 1 can beat n
only 2 - n-1 can beat 1

alice will win if and only if alice has (1 & n) or (n & n-1) or (1 - (n-1))
else bob win
*/