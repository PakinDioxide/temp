// PakinDioxide - Subtask 1
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k, s;
    cin >> n >> k >> s;
    ll a[n], l = 0, r = 0, ans = 0;
    for (int i = 0; i < n; i++) cin >> a[i], r += a[i];
    while (l <= r) {
        ll x = (l+r)/2, ok = 1;
        vector <ll> v;
        v.push_back(0);
        // cout << x << '\n';
        for (int i = 0; i < n; i++) {
            if (v.back() + a[i] <= x) v.back() += a[i];
            else if (a[i] <= x) v.push_back(a[i]);
            else {ok = 0; break;}
        }
        if (!ok || v.size() > 1) {l = x+1; continue;}
        sort(v.begin(), v.end());

        if (v.size() <= k) ans = x, r = x-1;
        else l = x+1;
    }
    cout << ans;
}