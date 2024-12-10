#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    string a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int j;
    cin >> j;
    for (int i = 0; i < j; i++) {
        vector <bool> alr(n);
        set <int> ans;
        int l, c = 0;
        string b, k;
        cin >> l >> b;
        for (int i = 0 ; i < m; i++) k.push_back(b[i]);
        for (int i = m; i <= l; i++) {
            for (int j = 0; j < n; j++) {
                if (alr[j]) continue;
                if (a[j] == k) {ans.insert(j+1); alr[j] = 1; c++;}
                if (c == n) break;
            }
            if (c == n) break;
            k.erase(k.begin());
            k.push_back(b[i]);
        }
        if (c == 0) cout << "OK";
        else for (auto v : ans) cout << v << ' ';
        cout << '\n';
    }
}
