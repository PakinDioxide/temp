#include <bits/stdc++.h>
#define ll long long

using namespace std;

int solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int k = n/(a+b+c);
    n %= a+b+c;
    int s = 0;
    if (s >= n) return 3*k;
    s = a;
    if (s >= n) return 3*k+1;
    s += b;
    if (s >= n) return 3*k+2;
    return 3*k+3;

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) cout << solve() << '\n';
}