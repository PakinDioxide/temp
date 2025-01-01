// PakinDioxide
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <int> seg[10000005];

vector <int> mx(int l, int r, int x, int y, int node) {
    if (x <= l && r <= y) return seg[node];
    else {
        int mid = (l+r)/2;
        vector <int> a, b;
        if (mid >= x) a = mx(l, mid, x, y, node*2+1);
        if (mid+1 <= y) b = mx(mid+1, r, x, y, node*2+2);
        if (a.size() > b.size()) return seg[node] = a;
        else return seg[node] = b;
    }
}

void st(int l, int r, int node, int idx, vector <int> k) {
    if (l == r) seg[node] = k;
    else {
        int mid = (l+r)/2;
        if (idx <= mid) st(l, mid, node*2+1, idx, k);
        else st(mid+1, r, node*2+2, idx, k);
        if (seg[node*2+1].size() > seg[node*2+2].size()) seg[node] = seg[node*2+1];
        else seg[node] = seg[node*2+2];
    }
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int n, mmx = 0, mmn = INT_MAX;
    cin >> n;
    vector <pair <int, int>> a(n);
    vector <tuple <int, int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        int l = a[i].first-a[i].second, r = a[i].first+a[i].second;
        v[i] = {r, l, i};
        mmn = min(mmn, l);
        mmx = max(mmx, r);
    }
    sort(v.begin(), v.end());
    mmn *= -1;
    vector <int> ans;
    vector <pair <int, int>> anss;
    for (auto [r, l, idx] : v) {
        // cout << r << ' ' << l << '\n';
        vector <int> k = mx(0, mmn+mmx, mmn+l, mmn+r, 0);
        k.push_back(idx);
        if (k.size() > ans.size()) ans = k;
        st(0, mmn+mmx, 0, mmn+l, k);
    }
    cout << ans.size() << '\n';
    for (int i : ans) cout << a[i].first << ' ' << a[i].second << '\n';
    // for (int i : ans) anss.emplace_back(a[i].second, a[i].first);
    // sort(anss.begin(), anss.end());
    // for (auto [y, x] : anss) cout << x << ' ' << y << '\n';
}