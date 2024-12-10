#include <bits/stdc++.h>

using namespace std;

#define int long long

int a[100005], b[100005], cnt = 0;

void merge(int l, int r) {
    if (l >= r) return;
    int mid = (l+r)/2;
    merge(l, mid);
    merge(mid+1, r);
    int x = l, y = mid+1, idx = l;
    while (x <= mid && y <= r) {
        if (a[x] > a[y]) b[idx++] = a[x++], cnt += r - y + 1;
        else b[idx++] = a[y++];
    }
    while (x <= mid) b[idx++] = a[x++];
    while (y <= r) b[idx++] = a[y++];
    for (int i = l; i <= r; i++) a[i] = b[i];
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    merge(0, n-1);
    cout << cnt;
}