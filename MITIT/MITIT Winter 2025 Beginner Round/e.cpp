#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    int cnt[n+5], a[n+5];
    memset(cnt, 0, sizeof(cnt));
    set <int> st;
    for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;
    for (int i = 1; i <= n; i++) if (!cnt[i]) st.insert(i);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            cnt[a[x]]--;
            if (!cnt[a[x]]) st.insert(a[x]);
            a[x] = y;
            if (!cnt[y]) st.erase(st.find(y));
            cnt[y]++;
        } else {
            int l, r;
            cin >> l >> r;
            if (st.size() > 0) cout << *st.begin() << '\n';
            else if (l > 1) cout << a[1] << '\n';
            else cout << a[n] << '\n';
        }
    }
}