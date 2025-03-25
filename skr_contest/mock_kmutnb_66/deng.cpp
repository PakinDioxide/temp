/*
    author  : PakinDioxide
    created : 25/03/2025 20:36
    task    : deng
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, q;
vector <bool> s;

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < (1 << n) - 1; i++) {
        char k;
        cin >> k;
        s.push_back(k=='1');
    }
    while (q--) {
        int x;
        cin >> x;
        int l = 0;
        while ((1 << l) <= x) l++;
        int v = 0;
        while (l < n) {
            v += x;
            if (s[x-1] == 0) s[x-1] = 1, x*=2;
            else s[x-1] = 0, x*=2, x++;
            l++;
        }
        cout << x << ' ' << v+x << '\n';
    }
}