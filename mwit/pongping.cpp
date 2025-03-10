#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n;
    pair <int, int> a[n];
    for (int i = 0; i < n; i++) cin >> x, x--, a[x].first = i+1;
    for (int i = 0; i < n; i++) {cin >> x, x--, a[x].second = i+1; if (a[x].second > a[x].first) swap(a[x].first, a[x].second);}
    sort(a, a+n);
    int cnt = 0, r = 0;
    for (int i = 0; i < n; i++) if (a[i].second >= r) cnt++, r = a[i].first;
    cout << cnt << '\n';
}