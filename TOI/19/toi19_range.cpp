/*
    author  : PakinDioxide
    created : 18/03/2025 14:06
    task    : toi19_range
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int seg[3200005];

void add(int l, int r, int idx, int x, int node) {
    if (l == r) seg[node] = max(seg[node], x);
    else {
        int mid = (l+r)/2;
        if (mid >= idx) add(l, mid, idx, x, node*2+1);
        else add(mid+1, r, idx, x, node*2+2);
        seg[node] = max(seg[node*2+1], seg[node*2+2]);
    }
}

int sum(int l, int r, int x, int y, int node) {
    if (x <= l && r <= y) return seg[node];
    else {
        int mid = (l+r)/2, mx = 0;
        if (mid >= x) mx = max(mx, sum(l, mid, x, y, node*2+1));
        if (mid+1 <= y) mx = max(mx, sum(mid+1, r, x, y, node*2+2));
        return mx;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, idx = 0;
    cin >> n;
    vector <int> cc;
    tuple <int, int, int> a[n];
    for (auto &[r, l, id] : a) cin >> l >> r, id = idx++, cc.emplace_back(l), cc.emplace_back(r);
    sort(cc.begin(), cc.end());
    for (auto &[r, l, id] : a) r = lower_bound(cc.begin(), cc.end(), r) - cc.begin() + 1, l = lower_bound(cc.begin(), cc.end(), l) - cc.begin() + 1, l = -l;
    sort(a, a+n);
    int ans[n+5], mx = 0;
    for (auto &[r, l, id] : a) {
        l = -l;
        int cnt = sum(1, cc.size(), l, r, 0) + 1;
        ans[id] = cnt;
        add(1, cc.size(), l, cnt, 0);
        mx = max(mx, cnt);
    }
    cout << mx << '\n';
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';
}