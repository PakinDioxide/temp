#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, thr = 3;
        cin >> n;
        if (n == 4 || n < 3) {cout << -1 << '\n'; continue;}
        if (n%3 == 1) n-=4;
        cout << n/3 << '\n';
    }
}