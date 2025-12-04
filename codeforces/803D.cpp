#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int k; cin >> k; cin.ignore();
    string s;
    getline(cin, s);
    vector <int> v;
    v.emplace_back(0);
    for (auto &e : s) if (e == ' ' || e == '-') v.back()++, v.emplace_back(0);
    else v.back()++;
    int l = 1, r = 1e6+5, ans = 0;
    while (l <= r) {
        int x = l + (r-l)/2;
        int s = 0, c = 1, ok = 1;
        for (auto &e : v) {
            if (s + e <= x) s += e;
            else if (e <= x) s = e, c++;
            else { ok = 0; break; }
        }
        if (c <= k && ok) ans = x, r = x-1;
        else l = x+1;
    }
    cout << ans << '\n';
}