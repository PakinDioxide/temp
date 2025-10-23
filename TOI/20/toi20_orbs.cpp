#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    int n, l, x, y;
    scanf("%lld %lld %lld %lld", &n, &l, &x, &y);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
    sort(arr, arr+n);
    multiset <int> a, b;
    for (int i = 0; i < x; i++) a.insert(arr[i]);
    for (int i = x; i < y; i++) b.insert(arr[i]);
    while (l--) {
        int p = (*prev(a.end()) + *prev(b.end()))/2, q = *prev(b.end()) - *prev(a.end());
        a.erase(prev(a.end())), b.erase(prev(b.end()));

        if (p > q) swap(p, q);
        if ((a.size() > 0 && *prev(a.end()) >= p) || (a.size() == 0 && b.size() > 0 && *b.begin() >= p) || (a.size() == 0 && b.size() == 0)) a.insert(p);
        else b.insert(p);

        if (a.size() < x) {
            a.insert(*b.begin());
            b.erase(b.begin());
            b.insert(q);
        } else if (*prev(a.end()) > q) {
            a.insert(q);
            b.insert(*prev(a.end()));
            a.erase(prev(a.end()));
        } else b.insert(q);
    }
    for (int i : a) printf("%lld ", i);
    for (int i : b) printf("%lld ", i);
    for (int i = y; i < n; i++) printf("%lld ", arr[i]);
}