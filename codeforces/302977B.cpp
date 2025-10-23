#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, x; cin >> n >> x;
    string s; cin >> s;
    ll ans = 0, cnt = 0; bool vis[26]; memset(vis, 0, sizeof(vis));
    while (x--) { char k; cin >> k; vis[k-'a'] = 1; }
    for (auto &e : s) {
        if (!vis[e-'a']) ans += cnt*(cnt+1)/2, cnt = 0;
        else cnt++;
    }
    ans += cnt*(cnt+1)/2;
    cout << ans << '\n';
}