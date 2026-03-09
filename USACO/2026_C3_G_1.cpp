#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

struct FEN {
    int sz;
    vector <int> fen;
    void build(int SZ) {
        sz = SZ;
        fen.resize(sz+1);
    }
    int qr(int idx) {
        int s = 0;
        for (int i = idx; i > 0; i -= i & -i) s += fen[i];
        return s;
    }
    void upd(int idx, int x) {
        for (int i = idx; i <= sz; i += i & -i) fen[i] += x;
    }
};

void solve() {
    int n; cin >> n;
    deque <int> dq;
    FEN cnt;
    cnt.build(n);
    int nd = 0;
    for (int i = 0, x; i < n; i++) cin >> x, dq.emplace_back(x), nd += cnt.qr(n) - cnt.qr(x), cnt.upd(x, 1);
    FEN F;
    int OF = n+5, OO = n+5;
    F.build(3*n+5);
    int CC = 0;
    for (int i = 0; i < n; i++) {
        F.upd(OF + dq[i]-i-1, 1);
        CC += abs(dq[i]-i-1);
    }
    vector <int> ANS;
    for (int RT = 0; RT < n; RT++) {
        // do sth
        // cout << "VA " << CC << '\n';
        if ((CC)/2 >= nd) ANS.emplace_back(RT);
        nd = nd - (n - dq.back()) + (dq.back()-1);
        assert(nd >= 0);
        F.upd(OO + dq.back() - n, -1);
        CC -= abs(dq.back() - n);
        OO++;
        dq.emplace_front(dq.back()), dq.pop_back();
        CC += F.qr(OO-1) - F.qr(F.sz) + F.qr(OO-1);
        F.upd(OO + dq.front() - 1, 1);
        CC += abs(dq.front() - 1);
    }
    cout << ANS.size() << '\n';
    for (int i = 0; i < (int) ANS.size(); i++) {
        cout << ANS[i];
        if (i < (int) ANS.size() - 1) cout << ' ';
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
}
