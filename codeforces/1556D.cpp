/*
    author  : PakinDioxide
    created : 05/04/2025 19:12
    task    : 1556D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll kor(int x, int y) {ll k; cout << "or " << x << ' ' << y << endl; cin >> k; return k;}
ll kand(int x, int y) {ll k; cout << "and " << x << ' ' << y << endl; cin >> k; return k;}
void answer(ll k) {cout << "finish " << k << endl;}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <ll> v;
    // find 1-3
    ll aob = kor(1, 2), boc = kor(2, 3), aoc = kor(1, 3);
    ll aab = kand(1, 2), bac = kand(2, 3), aac = kand(1, 3);
    ll axb = aob & ~aab, bxc = boc & ~bac, axc = aoc & ~aac;
    ll ab = 2*aab + axb, bc = 2*bac + bxc, ac = 2*aac + axc;
    ll abc = (ab + bc + ac)/2;
    v.emplace_back(abc-bc);
    v.emplace_back(abc-ac);
    v.emplace_back(abc-ab);
    for (int i = 4; i <= n; i++) {
        ll o = kor(i-1, i), a = kand(i-1, i);
        ll x = o & ~a;
        ll s = 2*a+x;
        v.emplace_back(s-v.back());
    }
    sort(v.begin(), v.end());
    answer(v[k-1]);
}

/*
xor = or & !and

001
010
011
100
101
*/