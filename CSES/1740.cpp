/*
    author  : PakinDioxide
    created : 31/03/2025 15:03
    task    : 1740
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll fen[2000005];

void add(int idx, int x) {
    for (int i = idx; i < 2000005; i += i & (-i)) fen[i] += x;
}

ll qr(int idx) {
    ll sum = 0;
    for (int i = idx; i > 0; i -= i & (-i)) sum += fen[i];
    return sum;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <tuple <int, int, int, int>> v;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 == y2) v.emplace_back(y1, 2, x1, x2);
        else {
            v.emplace_back(y1, 1, x1, x2);
            v.emplace_back(y2, 3, x1, x2);
        }
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for (auto [y, t, x1, x2] : v) {
        if (t == 1) add(x1+1000001, 1);
        else if (t == 3) add(x1+1000001, -1);
        else ans += qr(x2+1000001) - qr(x1+1000000);
    }
    cout << ans << '\n';
}