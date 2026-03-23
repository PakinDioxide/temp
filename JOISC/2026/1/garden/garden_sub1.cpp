#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2*3e2+5;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll H, W, N, XX; cin >> H >> W >> N >> XX;
    vector <tuple <ll, ll, ll, ll, ll>> Q(N);
    vector <ll> ccX, ccY;
    for (auto &[x1, y1, x2, y2, c] : Q) {
        cin >> x1 >> x2 >> y1 >> y2 >> c;
        ccX.emplace_back(x1);
        ccX.emplace_back(x2);
        ccY.emplace_back(y1);
        ccY.emplace_back(y2);
    }
    ll xl = LLONG_MAX,
       xr = LLONG_MIN,
       yl = LLONG_MAX,
       yr = LLONG_MIN;
    for (auto &[x1, y1, x2, y2, c] : Q) {
        xl = min(xl, x1);
        xr = max(xr, x2);
        yl = min(yl, y1);
        yr = max(yr, y2);
        cout << (xr - xl + 1) * (yr - yl + 1) << '\n';
    }
}
