#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[200005];

void solve() {
    string s;
    cin >> s;
    set <int> idx;
    for (int i = 0; i < s.size() - 3; i++) {
        if (s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0') idx.insert(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--;
        s[x] = y + '0';
        for (int i = max(0, x-3); i <= min(x, (int) s.size() - 3); i++) {
            if (s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0') idx.insert(i);
            else {
                auto id = idx.find(i);
                if (id != idx.end()) idx.erase(id);
            }
        }
        if (idx.size()) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}