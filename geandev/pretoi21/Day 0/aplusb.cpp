/*
    author  : PakinDioxide
    created : 06/05/2025 00:36
    task    : aplusb
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, m; ll k;
    scanf("%d %d %lld", &n, &m, &k);
    vector <int> a(n), b(m);
    for (auto &e : a) scanf("%d", &e);
    for (auto &e : b) scanf("%d", &e);
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    int l = 0, r = 2e9, ans = 0;
    while (l <= r) {
        int x = l + (r-l)/2, idx = m-1; ll c = 0;
        for (int i = 0; i < n; i++) {
            while (idx >= 0 && a[i] + b[idx] > x) idx--;
            c += idx+1;
        }
        if (c >= k) r = x-1, ans = x;
        else l = x+1;
    }
    printf("%d\n", ans);
}