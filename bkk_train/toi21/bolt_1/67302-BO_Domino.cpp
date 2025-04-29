#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

const int mxN = 5e5+5;

int a[mxN], b[mxN], l[mxN], r[mxN], p[mxN];
pair <int, pair <int, int>> vl[mxN], vr[mxN];

void solve() {
    int n, sum = 0;
    cin >> n;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    memset(p, 0, sizeof(p));
    p[0] = 0;
    for (int i = 1; i <= n; i++) cin >> b[i], p[i] = p[i-1] + b[i], sum += b[i];
    p[n+1] = p[n];
    for (int i = 1; i <= n; i++) cin >> a[i];
    // cout << sum << '\n';
    // return;
    stack <pair <int, pair <int, int>>> st;
    st.emplace(0, make_pair(LLONG_MAX, LLONG_MAX));
    for (int i = 1; i <= n; i++) {
        int e = a[i];
        while (st.top().second.first <= e) e += st.top().second.second, st.pop();
        l[i] = st.top().first;
        st.emplace(i, make_pair(a[i], e));
    }
    while (!st.empty()) st.pop();
    st.emplace(n+1, make_pair(LLONG_MAX, LLONG_MAX));
    for (int i = n; i >= 1; i--) {
        int e = a[i];
        while (st.top().second.first <= e) e += st.top().second.second, st.pop();
        r[i] = st.top().first;
        st.emplace(i, make_pair(a[i], e));
    }
    // int mx = 0;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = i+1; j <= n; j++) {
    //         int k = 0;
    //         if (r[i]-1 < l[j]+1) k = p[r[i]-1] - p[i-1] + p[j] - p[l[j]];
    //         else k = p[j]-p[i-1];
    //         mx = max(mx, k);
    //     }
    // }
    // cout << mx << '\n';
    // return;
    // for (int i = 1; i <= n; i++) cout << l[i] << ' '; cout << '\n';
    // for (int i = 1; i <= n; i++) cout << r[i] << ' '; cout << '\n';
    memset(vl, 0, sizeof(vl));
    memset(vr, 0, sizeof(vr));
    vl[n] = make_pair(p[n]-p[l[n]], make_pair(l[n], n));
    for (int i = n-1; i >= 1; i--) {
        vl[i] = make_pair(p[i]-p[l[i]], make_pair(l[i], i));
        vl[i] = max(vl[i], vl[i+1]);
    }
    vr[1] = make_pair(p[r[1]-1]-p[0], make_pair(1, -r[1]));
    for (int i = 2; i <= n; i++) {
        vr[i] = make_pair(p[r[i]-1]-p[i-1], make_pair(i, -r[i]));
        vr[i] = max(vr[i], vr[i-1]);
    }
    int mx = 0;
    for (int i = 1; i < n; i++) {
        pair <int, pair <int, int>> k = vl[i+1];
        int kk = 0;
        if (k.second.first > i) kk = p[min(k.second.first-1, r[i]-1)] - p[i-1];
        // if (r[i] > k.second.second) kk += p[min(n, r[i])] - p[k.second.second];
        mx = max(mx, kk+k.first);
        // kk = p[min(r[i], n)] - p[i-1];
        // if (k.second.second > r[i]) kk += p[k.second.second] - p[min(r[i], n)];
        // mx = max(mx, kk);
        // if (i==2) {
        //     cout << kk << '\n';
        //     cout << k.second.first << ' ' << k.second.second << '\n';
        //     cout << i << ' ' << r[i] << '\n';
        //     break;
        // }
    }
    for (int i = 2; i <= n; i++) {
        pair <int, pair <int, int>> k = vr[i-1];
        k.second.second *= -1;
        int kk = 0;
        if (k.second.second < i) kk = p[i] - p[max(k.second.second, l[i])];
        mx = max(mx, kk+k.first);
        // if (i==n) {
          //     cout << kk << '\n';
         //     cout << k.second.first << ' ' << k.second.second << '\n';
        //     cout << i << ' ' << r[i] << '\n';
        //     break;
        // }
    }
    cout << mx << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}