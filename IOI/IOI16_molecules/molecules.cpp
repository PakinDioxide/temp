#include "molecules.h"
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> find_subset(int l, int r, vector<int> w) {
    int n = w.size();
    vector <pair <ll, int>> a(n);
    for (int i = 0; i < n; i++) a[i] = make_pair(w[i], i);
    a.emplace_back(0, -1);
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++) a[i].first += a[i-1].first;
    vector <int> ans;
    for (int i = 1; i <= n; i++) {
        if (a[i].first < l) continue;
        ll x = a[i].first - l;
        int idx = prev(upper_bound(a.begin(), a.begin() + i, make_pair(x, INT_MAX))) - a.begin();
        ll ss = a[i].first - a[idx].first;
        if (ss >= l && ss <= r) {
            for (int j = idx+1; j <= i; j++) ans.emplace_back(a[j].second);
            break;
        }
    }
    return ans;
}
