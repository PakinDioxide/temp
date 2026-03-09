#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    vector <int> a;
    a.emplace_back(n);
    a.emplace_back(0);
    a.emplace_back(n);
    for (int i = 1; i < n; i++) {
        vector <int> v(i);
        for (auto &e : v) cin >> e;
        int ok[n+1]; memset(ok, 0, sizeof(ok));
        ok[n] = 1;
        for (int j = 0; j < ceil(i/2.0); j++) ok[v[j]] = 1;
        for (int ii = 0; ii < (int) a.size()-1; ii++) {
            if (ok[a[ii]] && ok[a[ii+1]]) {
                a.insert(a.begin()+ii+1, i);
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << '\n';
}
