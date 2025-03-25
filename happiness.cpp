/*
    author  : PakinDioxide
    created : 25/03/2025 11:00
    task    : happiness
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll seg[800005], laz[800005];

void push(int node) {
    seg[node*2+1] += laz[node];
    seg[node*2+2] += laz[node];
    laz[node*2+1] += laz[node];
    laz[node*2+2] += laz[node];
    laz[node] = 0;
}

void add(int l, int r, int x, int y, int k, int node) {
    if (x <= l && r <= y) seg[node] += k, laz[node] += k;
    else {
        push(node);
        int mid = l + (r-l)/2;
        if (x <= mid) add(l, mid, x, y, k, node*2+1);
        if (mid+1 <= y) add(mid+1, r, x, y, k, node*2+2);
        seg[node] = min(seg[node*2+1], seg[node*2+2]);
    }
}

ll sum(int l, int r, int x, int y, int node) {
    if (x <= l && r <= y) return seg[node];
    else {
        push(node);
        int mid = l + (r-l)/2;
        ll mn = LLONG_MAX;
        if (x <= mid) mn = min(mn, sum(l, mid, x, y, node*2+1));
        if (mid+1 <= y) mn = min(mn, sum(mid+1, r, x, y, node*2+2));
        return mn;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int a[n+1], cnt = 0;
    vector <pair <int, int>> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] >= 0) add(1, n, i, n, a[i], 0), cnt++;
        else v.emplace_back(a[i], i);
    }
    // for (int i = 1; i <= n; i++) cout << sum(1, n, i, i, 0) << ' ';
    // cout << '\n';
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (auto &[e, idx] : v) {
        if (sum(1, n, idx, n, 0) >= -e) /*cout << sum(1, n, idx, n, 0) << '\n', */add(1, n, idx, n, e, 0), cnt++;
        // for (int i = 1; i <= n; i++) cout << sum(1, n, i, i, 0) << ' ';
        // cout << '\n';
    }
    cout << cnt << '\n';
}