// PakinDioxide - TLE TEST
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, q;
    cin >> n >> m;
    ll a[n], b[m], sum = 0, summ = 0;
    for (int i = 0; i < n; i++) cin >> a[i], summ += a[i];
    for (int i = 0; i < m; i++) cin >> b[i], sum += summ*b[i];
    cin >> q;
    sort(a, a+n), sort(b, b+m);
}