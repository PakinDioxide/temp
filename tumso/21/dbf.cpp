#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    pair <int, int> a[n];
    vector <tuple <int, int, int>> v;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a[i] = {l, r};
        v.emplace_back(l, 1, i);
        v.emplace_back(r+1, 0, i);
    }
    sort(v.begin(), v.end());
    int r = 0, ans = n;
    set <pair <int, int>> st;
    for (int i = 0; i < v.size(); i++) {
        auto [idx, t, ii] = v[i];
        // cout << "K " << t << ' ' << a[ii].first << ' ' << a[ii].second << ' ' << idx << '\n';
        if (t == 1) st.emplace(a[ii].second - a[ii].first, ii);
        else {
            auto iidx = st.lower_bound({a[ii].second - a[ii].first, ii});
            if (!((*iidx) != make_pair(a[ii].second - a[ii].first, ii))) {
                st.erase(iidx);
                // cout << "ER" << (*iidx).first << ' ' << (*iidx).second << '\n';
                ans--;
            }
        }
        if (i < v.size()-1 && get<0>(v[i]) == get<0>(v[i+1])) continue; //{cout << "HA\n"; continue;}
        for (int i = 0; i < idx - r && !st.empty(); i++) st.erase(st.begin());
        // cout << idx << ' ';
        // cout << "S : " << st.size() << '\n';
        r = idx;
        // for (auto kk : st) cout << kk.first << ' ';
        // cout << '\n';
    }
    cout << ans;
}