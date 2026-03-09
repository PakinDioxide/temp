#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Node {
    int cnt;
    Node *v[2];
    Node () : cnt(0), v({NULL, NULL}) {}
};

Node *root = new Node();

void ins(int k, int b, Node *u) {
    if (b == -1) {
        u->cnt = 1;
        return;
    }
    int x = ((k & (1 << b)) > 0);
    if (!u->v[x]) u->v[x] = new Node();
    ins(k, b-1, u->v[x]);
    u->cnt = (u->v[0] ? u->v[0]->cnt : 0) + (u->v[1] ? u->v[1]->cnt : 0);
}

void del(int k, int b, Node *u) {
    if (b == -1) {
        u->cnt = 0;
        return;
    }
    int x = ((k & (1 << b)) > 0);
    if (u->v[x]) del(k, b-1, u->v[x]);
    u->cnt = (u->v[0] ? u->v[0]->cnt : 0) + (u->v[1] ? u->v[1]->cnt : 0);
}

int qr(int k, int b, Node *u) {
    if (b == -1) return 0;
    int x = ((k & (1 << b)) > 0);
    if (u->v[x] && u->v[x]->cnt) return x * (1 << b) + qr(k, b-1, u->v[x]);
    else return (!x) * (1 << b) + qr(k, b-1, u->v[!x]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int q; cin >> q;
    while (q--) {
        int t, x; cin >> t >> x;
        if (t == 0) ins(x, 30, root);
        else if (t == 1) del(x, 30, root);
        else cout << (x ^ qr(x, 30, root)) << '\n';
    }
}

