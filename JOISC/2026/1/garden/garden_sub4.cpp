#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2*5e3+5;

struct SEG {
    struct node {
        ll val = 0, lz = 0;
        node *L = nullptr, *R = nullptr;
    };

    node *RT = new node;
    
    void push(node *u) {
        if (u->L == nullptr) u->L = new node;
        if (u->R == nullptr) u->R = new node;
        u->L->val += u->lz;
        u->L->lz += u->lz;
        u->R->val += u->lz;
        u->R->lz += u->lz;
        u->lz = 0;
    }

    void upd(int l, int r, int x, int y, ll k, node *u) {
        if (x <= l && r <= y) u->val += k, u->lz += k;
        else {
            push(u);
            int m = l + (r-l)/2;
            if (m >= x) upd(l, m, x, y, k, u->L);
            if (m+1 <= y) upd(m+1, r, x, y, k, u->R);
            u->val = max(u->L->val, u->R->val);
        }
    }

    void st(int l, int r, int x, ll k, node *u) {
        if (l == r) u->val = max(u->val, k);
        else {
            push(u);
            int m = l + (r-l)/2;
            if (m >= x) st(l, m, x, k, u->L);
            else st(m+1, r, x, k, u->R);
            u->val = max(u->L->val, u->R->val);
        }
    }

    int QR_L(int l, int r, ll k, node *u) {
        if (u->val < k) return -1;
        if (l == r) return l;
        else {
            push(u);
            int m = l + (r-l)/2;
            if (u->L->val >= k) return QR_L(l, m, k, u->L);
            else return QR_L(m+1, r, k, u->R);
        }
    }

    int QR_R(int l, int r, ll k, node *u) {
        if (u->val < k) return -1;
        if (l == r) return l;
        else {
            push(u);
            int m = l + (r-l)/2;
            if (u->R->val >= k) return QR_R(m+1, r, k, u->R);
            else return QR_R(l, m, k, u->L);
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
    /*
    for (int i = 0; i < 2*N; i++) {
        X[i].build(0, 2*N, 1);
        Y[i].build(0, 2*N, 1);
    }
    XT.build(0, 2*N, 1);
    YT.build(0, 2*N, 1);
    */
    for (auto &[x1, y1, x2, y2, c] : Q) {
        x1 = lower_bound(ccX.begin(), ccX.end(), x1) - ccX.begin();
        x2 = lower_bound(ccX.begin(), ccX.end(), x2) - ccX.begin();
        y1 = lower_bound(ccY.begin(), ccY.end(), y1) - ccY.begin();
        y2 = lower_bound(ccY.begin(), ccY.end(), y2) - ccY.begin();

        for (int i = x1; i <= x2; i++) {
            X[i].upd(0, 2*N, y1, y2, c, X[i].RT);
            XT.st(0, 2*N, i, X[i].RT->val, XT.RT);
        }
        for (int i = y1; i <= y2; i++) {
            Y[i].upd(0, 2*N, x1, x2, c, Y[i].RT);
            YT.st(0, 2*N, i, Y[i].RT->val, YT.RT);
        }
        
        // for (int i = 0; i < 2*N; i++) cout << X[i].seg[1] << ' '; cout << '\n';

        int xl = XT.QR_L(0, 2*N, XX, XT.RT),
            xr = XT.QR_R(0, 2*N, XX, XT.RT),
            yl = YT.QR_L(0, 2*N, XX, YT.RT),
            yr = YT.QR_R(0, 2*N, XX, YT.RT);
        
        if (xl == -1) { cout << 0 << '\n'; continue; }

        // cout << (xr - xl + 1) * (yr - yl + 1) << '\n';

        // cout << ccX[xl] << ' ' << ccX[xr] << ' ' << ccY[yl] << ' ' << ccY[yr] << '\n';

        cout << (ccX[xr] - ccX[xl] + 1) * (ccY[yr] - ccY[yl] + 1) << '\n';
    }
}
