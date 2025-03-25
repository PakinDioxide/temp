#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll a[n];
    for (auto &e : a) cin >> e;
    sort(a, a+n);
    int l = 1, r = n-2;
    while (l < r) {
        if (a[n-1] - a[l] > a[r] - a[0]) l++;
        else if (a[n-1] - a[l] < a[r] - a[0]) r--;
        else {cout << a[r] - a[0] << '\n'; exit(0);}
    }
    cout << -1 << '\n';
}