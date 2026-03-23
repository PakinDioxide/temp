#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e4+5;

int n;
int a[mxN];
int b[mxN];

vector <vector <int>> OP[20];

void recur(int l, int r, int k) {
    if (l == r) return;
    int m = l + (r-l)/2;
    for (int i = l; i <= r; i++) b[i] = (a[i] > m);
    vector <pair <int, int>> v;
    for (int i = l; i <= r; i++) {
        if (v.empty() || b[v.back().second] != b[i]) v.emplace_back(i, i);
        else v.back().second = i;
    }
    int it = 0;
    while (v.size() > 2 || b[v[0].first]) {
        /*
        cout << "# " << it << '\n';
        for (auto &[x, y] : v) cout << x << ' ' << y << '\n';
        */
        if ((int) OP[k].size() <= it) OP[k].emplace_back(vector <int>());
        int s = 0; for (auto &e : OP[k][it]) s += e;
        while (s < l - 1) OP[k][it].emplace_back(1), s++;
        int c = 0;
        if (!(b[v[0].first])) for (int i = v[0].first; i <= v[0].second; i++) OP[k][it].emplace_back(1);
        for (int i = !(b[v[0].first]); i < (int) v.size(); ) {
            c++;
            if (c % 3 == 1) {
                if (i+1 == (int) v.size()) continue;
                OP[k][it].emplace_back(v[i+1].second - v[i].first + 1);
                reverse(a+v[i].first, a+v[i+1].second+1);
                reverse(b+v[i].first, b+v[i+1].second+1);
                i += 2;
            } else if (c % 3 == 2) {
                for (int ii = v[i].first; ii <= v[i].second; ii++) OP[k][it].emplace_back(1);
                i += 2;
            } else {
                OP[k][it].emplace_back(v[i].second - v[i-1].first + 1);
                reverse(a+v[i-1].first, a+v[i].second+1);
                reverse(b+v[i-1].first, b+v[i].second+1);
                i += 1;
            }
        }
        v.clear();
        for (int i = l; i <= r; i++) {
            if (v.empty() || b[v.back().second] != b[i]) v.emplace_back(i, i);
            else v.back().second = i;
        }
        it++;
    }
    /*
    cout << "# " << k << ' ' << l << ' ' << r << '\n';
    for (int i = 1; i <= n; i++) cout << a[i] << ' '; cout << '\n';
    */
    recur(l, m, k+1);
    recur(m+1, r, k+1);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    recur(1, n, 0);
    vector <vector <int>> ans;
    int sz = 0;
    for (int i = 0; i < 20; i++) {
        for (auto &v : OP[i]) {
            sz++;
            int s = 0;
            for (auto &e : v) s += e;
            while (s < n) v.emplace_back(1), s++;
            if (v.size() == 1) continue;
            ans.emplace_back(v);
        }
    }
    if ((int) sz % 2 == 1) {
        ans.emplace_back(vector <int> ());
        for (int i = 0; i < n; i++) ans.back().emplace_back(1);
    }
    cout << ans.size() << '\n';
    int it = 0;
    for (auto &v : ans) {
        cout << v.size() << ' ';
        if (it % 2 == 1) reverse(v.begin(), v.end());
        it++;
        for (auto &e : v) cout << e << ' ';
        cout << '\n';
    }
}

