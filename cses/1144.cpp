#include <bits/stdc++.h>

using namespace std;

int n, q, sz, fen[800005];

void add(int idx, int k) {
    for (int i = idx; i <= sz; i += (i & (-i))) fen[i] += k;
}
int sum(int l, int r) {
    int s = 0;
    for (int i = r; i > 0; i -= (i & (-i))) s += fen[i];
    for (int i = l; i > 0; i -= (i & (-i))) s -= fen[i];
    return s;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    set <int> sl;
    int a[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i], sl.insert(a[i]);
    vector <tuple <char, int, int>> qs(q);
    for (auto &[k, x, y] : qs) {
        cin >> k >> x >> y;
        if (k == '!') sl.insert(y);
        else sl.insert(x), sl.insert(y);
    }
    int idx = 0;
    unordered_map <int, int> mp;
    for (auto s : sl) mp[s] = ++idx;
    for (int i = 1; i <= n; i++) a[i] = mp[a[i]];
    for (auto &[k, x, y] : qs) {
        if (k == '!') y = mp[y];
        else x = mp[x], y = mp[y];
    }
    sz = sl.size();
    for (int i = 1; i <= n; i++) add(a[i], 1);
    for (auto &[k, x, y] : qs) {
        if (k == '!') {
            add(a[x], -1);
            add(y, 1);
            a[x] = y;
        } else {
            cout << sum(x-1, y) << '\n';
        }
    }
}