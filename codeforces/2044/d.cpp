#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, idx = 0;
    cin >> n;
    int a[n+1];
    map <int, int> cnt;
    vector <int> no;
    for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;
    for (int i = 1; i <= n; i++) if (!cnt[i]) no.push_back(i);
    cnt.clear();
    for (int i = 1; i <= n; i++) {
        int j = i;
        if (cnt[a[i]]) {
            a[i] = no[idx++];
            continue;
        }
        cnt[a[i]]++;
        while (j <= n && a[j] == a[i]) j++;
        for (int k = i+1; k < j; k++) a[k] = no[idx++];
        i = j-1;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}