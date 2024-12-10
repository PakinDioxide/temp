#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, a[100005], b[100005], p[100005], ans = 0;
pair <int, int> v[100005];

void ms(int l, int r) {
    if (l >= r) return;
    int mid = (l + r)/2;
    ms(l, mid);
    ms(mid+1, r);
    p[l] = 0;
    for (int i = l+1; i <= mid+1; i++) p[i] = p[i-1] + a[i-1];
    int i = l, j = mid+1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++], ans += p[mid+1] - p[i] + a[j-1]*(mid+1-i);
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (; l <= r; l++) a[l] = b[l];
}

int32_t main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld %lld", &v[i].second, &v[i].first);
    sort(v, v+n);
    for (int i = 0; i < n; i++) a[i] = v[i].second;
    ms(0, n-1);
    printf("%lld", ans);
}