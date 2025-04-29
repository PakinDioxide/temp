/*
    author  : PakinDioxide
    created : 26/04/2025 19:58
    task    : 67302-BO-Bishop
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair <ll, ll> C(ll x, ll y) { return make_pair(x-y, x+y); }
map <ll, ll> XM, YM;
set <pair <ll, ll>> M;
vector <ll> Xo, Xe, Yo, Ye;

void solve() {
    XM.clear(), YM.clear(), M.clear(), Xo.clear(), Xe.clear(), Yo.clear(), Ye.clear();
    int n, m;
    cin >> n;
    ll mxXo = 0, mxXe = 0, mxYo = 0, mxYe = 0;
    while (n--) {
        ll x, y;
        cin >> x >> y;
        tie(x, y) = C(x, y);
        M.emplace(x, y);
        // cout << "K " << x << ' ' << y << '\n';
        XM[x]++, YM[y]++;
        if (x % 2 == 0)  mxXo = max(mxXo, XM[x]);
        else mxXe = max(mxXe, XM[x]);
        if (y % 2 == 0) mxYo = max(mxYo, YM[y]);
        else mxYe = max(mxYe, YM[y]);
    }
    for (auto &e : XM) {
        if (e.first % 2 == 0) {if (e.second == mxXo) Xo.emplace_back(e.first);}
        else {if (e.second == mxXe) Xe.emplace_back(e.first);}
    }
    for (auto &e : YM) {
        if (e.first % 2 == 0) {if (e.second == mxYo) Yo.emplace_back(e.first);}
        else {if (e.second == mxYe) Ye.emplace_back(e.first);}
    }
    int q;
    cin >> q;
    while (q--) {
        ll x, y;
        cin >> x >> y;
        tie(x, y) = C(x, y);
        // cout << "Q " << x << ' ' << y << '\n';
        ll mx = -1, my = -1;
        if (x % 2 == 0) {for (auto &e : Xo) if (M.find({e, y}) == M.end()) {mx = 0; break;} if (Xo.empty()) mx = 0;}
        else {for (auto &e : Xe) if (M.find({e, y}) == M.end()) {mx = 0; break;} if (Xe.empty()) mx = 0;}
        if (y % 2 == 0) {for (auto &e : Yo) if (M.find({x, e}) == M.end()) {my = 0; break;} if (Yo.empty()) my = 0;}
        else {for (auto &e : Ye) if (M.find({x, e}) == M.end()) {my = 0; break;} if (Ye.empty()) my = 0;}
        if (x % 2 == 0) mx += mxXo;
        else mx += mxXe;
        if (y % 2 == 0) my += mxYo;
        else my += mxYe;
        cout << max(mx+YM[y], my+XM[x])+1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}