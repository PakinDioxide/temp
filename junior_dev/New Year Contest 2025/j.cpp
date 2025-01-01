#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, m;
    cin >> n >> m;
    int shf = 0, r = 0, ee = 0, cnt = 0;
    m++;
    for (int i = 0; i < n; i+=m) r = max(r, i), cnt++;
    if (cnt == 0) {cout << 1; return;}
    shf = m*(m-(n%m));
    cout << "CNT " << cnt << '\n';
    while (cnt > 1) {
        // cout << "HA : ";
        m *= m;
        ee = r;
        r = cnt = 0;
        for (int i = shf; i <= ee; i += m) r = max(r, i), cnt++; //, cout << i << ' ';
        // cout << '\n';
        shf += m*(m-(cnt%m));
    }
    if (cnt) ee = r;
    // while (v.size() > 1) {
    //     // cout << "SHF : " << shf << '\n';
    //     // for (int i : v) cout << i << ' ';
    //     // cout << '\n';
    //     for (int i = shf; i < v.size(); i+=m) v2.push_back(v[i]);
    //     shf = m-((v.size()-shf) % m);
    //     ee = v.back();
    //     v = v2;
    //     v2 = v3;
    // }
    // if (v.size()) ee = v[0];
    cout << ee+1 << '\n'; 
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    while (q--) solve();
}