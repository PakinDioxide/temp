#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    int x = 1, r = 0, k = 0;
    vector <int> a;
    while ((x << 1) <= n) x = (x << 1), r = x-1;
    if (n - (n % 2) > x) {
        if (n % 2 == 0) {
            for (int i = 1; i <= n; i++) {
                if (i == r) continue;
                if (a.size() % 2 == 1) k |= i;
                else k &= i;
                a.push_back(i);
            }
            k |= r;
            a.push_back(r);
        } else {
            n--;
            for (int i = 1; i <= n; i++) {
                if (i == r) continue;
                if (a.size() % 2 == 1) k |= i;
                else k &= i;
                a.push_back(i);
            }
            k |= r;
            a.push_back(r);
            n++;
            k &= n;
            a.push_back(n);
        }
    } else {
        if (n % 2 == 0) {
            n -= 2;
            x = 1, r = 0, k = 0;
            while ((x << 1) <= n) x = (x << 1), r = x-1;
            for (int i = 1; i <= n; i++) {
                if (i == r) continue;
                if (a.size() % 2 == 1) k |= i;
                else k &= i;
                a.push_back(i);
            }
            k |= r;
            a.push_back(r);
            n++;
            k &= n;
            a.push_back(n);
            n++;
            k |= n;
            a.push_back(n);
        } else {
            n -= 3;
            x = 1, r = 0, k = 0;
            while ((x << 1) <= n) x = (x << 1), r = x-1;
            for (int i = 1; i <= n; i++) {
                if (i == r) continue;
                if (a.size() % 2 == 1) k |= i;
                else k &= i;
                a.push_back(i);
            }
            k |= r;
            a.push_back(r);
            n++;
            k &= n;
            a.push_back(n);
            n++;
            k |= n;
            a.push_back(n);
            n++;
            k &= n;
            a.push_back(n);
        }
    }
    cout << k << '\n';
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}