/*
    author  : PakinDioxide
    created : 18/05/2025 21:12
    task    : ORDERSET_seg_tree
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, seg[4*mxN];
pair <char, int> a[mxN];
vector <int> v;

void upd(int l, int r, int idx, int x, int node) {
    if (l == r) seg[node] = x;
    else {
        int mid = l + (r-l)/2;
        if (mid >= idx) upd(l, mid, idx, x, node*2+1);
        else upd(mid+1, r, idx, x, node*2+2);
        seg[node] = seg[node*2+1] + seg[node*2+2];
    }
}

int qr1(int l, int r, int x, int node) {
    if (l == r) return l;
    else {
        int mid = l + (r-l)/2;
        if (seg[node*2+1] >= x) return qr1(l, mid, x, node*2+1);
        else return qr1(mid+1, r, x - seg[node*2+1], node*2+2);
    }
}

int qr2(int l, int r, int x, int y, int node) {
    if (x <= l && r <= y) return seg[node];
    else {
        int mid = l + (r-l)/2, s = 0;
        if (mid >= x) s += qr2(l, mid, x, y, node*2+1);
        if (mid+1 <= y) s += qr2(mid+1, r, x, y, node*2+2);
        return s;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second, a[i].second -= (a[i].first == 'C'), v.emplace_back(a[i].second);
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++) {
        auto [t, x] = a[i]; if (t != 'K') x = upper_bound(v.begin(), v.end(), x) - v.begin();
        if (t == 'I') upd(1, n, x, 1, 0);
        else if (t == 'D') upd(1, n, x, 0, 0);
        else if (t == 'K') {
            if (seg[0] < x) cout << "invalid\n";
            else cout << v[qr1(1, n, x, 0)-1] << '\n';
        } else cout << qr2(1, n, 1, x, 0) << '\n';
    }
}