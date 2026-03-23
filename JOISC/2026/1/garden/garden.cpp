#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2*3e2+5;

struct SEG {
    ll seg[4*mxN], lz[4*mxN];
    
    void push(int u) {
        seg[u<<1] += lz[u];
        seg[u<<1|1] += lz[u];
        lz[u<<1] += lz[u];
        lz[u<<1|1] += lz[u];
        lz[u] = 0;
    }

    void build(int l, int r, int u) {
        if (l == r) seg[u] = lz[u] = 0;
        else {
            int m = l + (r-l)/2;
            build(l, m, u<<1);
            build(m+1, r, u<<1|1);
            seg[u] = max(seg[u<<1], seg[u<<1|1]);
            lz[u] = 0;
        }
    }

    void upd(int l, int r, int x, int y, ll k, int u) {
        if (x <= l && r <= y) seg[u] += k, lz[u] += k;
        else {
            push(u);
            int m = l + (r-l)/2;
            if (m >= x) upd(l, m, x, y, k, u<<1);
            if (m+1 <= y) upd(m+1, r, x, y, k, u<<1|1);
            seg[u] = max(seg[u<<1], seg[u<<1|1]);
        }
    }

    void st(int l, int r, int x, ll k, int u) {
        if (l == r) seg[u] = max(seg[u], k);
        else {
            push(u);
            int m = l + (r-l)/2;
            if (m >= x) st(l, m, x, k, u<<1);
            else st(m+1, r, x, k, u<<1|1);
            seg[u] = max(seg[u<<1], seg[u<<1|1]);
        }
    }

    int QR_L(int l, int r, ll k, int u) {
        if (seg[u] < k) return -1;
        if (l == r) return l;
        else {
            push(u);
            int m = l + (r-l)/2;
            if (seg[u<<1] >= k) return QR_L(l, m, k, u<<1);
            else return QR_L(m+1, r, k, u<<1|1);
        }
    }

    int QR_R(int l, int r, ll k, int u) {
        if (seg[u] < k) return -1;
        if (l == r) return l;
        else {
            push(u);
            int m = l + (r-l)/2;
            if (seg[u<<1|1] >= k) return QR_R(m+1, r, k, u<<1|1);
            else return QR_R(l, m, k, u<<1);
        }
    }
} X[mxN], Y[mxN], XT, YT;

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
    sort(ccX.begin(), ccX.end());
    sort(ccY.begin(), ccY.end());
    ccX.resize(unique(ccX.begin(), ccX.end()) - ccX.begin());
    ccY.resize(unique(ccY.begin(), ccY.end()) - ccY.begin());
    for (int i = 0; i < 2*N; i++) {
        X[i].build(0, 2*N, 1);
        Y[i].build(0, 2*N, 1);
    }
    XT.build(0, 2*N, 1);
    YT.build(0, 2*N, 1);
    for (auto &[x1, y1, x2, y2, c] : Q) {
        x1 = lower_bound(ccX.begin(), ccX.end(), x1) - ccX.begin();
        x2 = lower_bound(ccX.begin(), ccX.end(), x2) - ccX.begin();
        y1 = lower_bound(ccY.begin(), ccY.end(), y1) - ccY.begin();
        y2 = lower_bound(ccY.begin(), ccY.end(), y2) - ccY.begin();

        for (int i = x1; i <= x2; i++) {
            X[i].upd(0, 2*N, y1, y2, c, 1);
            XT.st(0, 2*N, i, X[i].seg[1], 1);
        }
        for (int i = y1; i <= y2; i++) {
            Y[i].upd(0, 2*N, x1, x2, c, 1);
            YT.st(0, 2*N, i, Y[i].seg[1], 1);
        }
        
        // for (int i = 0; i < 2*N; i++) cout << X[i].seg[1] << ' '; cout << '\n';

        int xl = XT.QR_L(0, 2*N, XX, 1),
            xr = XT.QR_R(0, 2*N, XX, 1),
            yl = YT.QR_L(0, 2*N, XX, 1),
            yr = YT.QR_R(0, 2*N, XX, 1);
        
        if (xl == -1) { cout << 0 << '\n'; continue; }

        // cout << ccX[xl] << ' ' << ccX[xr] << ' ' << ccY[yl] << ' ' << ccY[yr] << '\n';

        cout << (ccX[xr] - ccX[xl] + 1) * (ccY[yr] - ccY[yl] + 1) << '\n';
    }
}
