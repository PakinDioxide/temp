/*
    author  : PakinDioxide
    created : 18/03/2025 15:26
    task    : toi19_jewelry
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    deque <pair <ll, int>> st;
    st.emplace_back(LLONG_MAX, -1);
    ll h[n+1], idx[n+1], p[n+1], pidx = 0, ans = 0, sum = 0;
    idx[0] = 0, h[0] = (s[0] == 'T'), p[0] = 0;
    for (int i = 1; i < n; i++) h[i] = (s[i] == 'T' ? h[i-1]+1 : 0);
    for (int i = 1; i < n; i++) {if (s[i] == 'T' && s[i-1] == 'T') idx[i] = idx[i-1]; else idx[i] = i;}
    for (int i = 0; i < n; i++) {
        if (s[i] == 'F') {
            if (i == 0) continue;
            for (int j = h[i-1]-1; j > 0; j--) st.emplace_back(j, idx[i-1] + (h[i-1] - j));
            sum = 0;
        } else {
            while (st.back().first <= h[i]) st.pop_back(), pidx--;
            st.emplace_back(h[i], idx[i]);
        }
        for (int i = pidx; i < st.size()-1; i++) {
            p[i+1] = p[i] + st[i+1].first * (st[i+1].second - st[i].second);
            pidx++;
        }
        ans += sum + p[pidx];
        sum += h[i];
    }
    cout << ans << '\n';
}