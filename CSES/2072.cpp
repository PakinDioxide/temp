#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Node {
    int key, prior, cnt;
    Node *l, *r;
    Node(int x) : key(x), prior(rand()), l(nullptr), r(nullptr), cnt(1) {}
};

int cnt(Node *&t) {
    return t ? t->cnt : 0;
}

void upd_cnt(Node *&t) {
    if (!t) return;
    t->cnt = 1 + cnt(t->l) + cnt(t->r);
}

void split(Node *t, Node *&l, Node *&r, int key) {
    if (!t) { l = r = nullptr; return; }
    int c = cnt(t->l);
    if (c < key) split(t->r, t->r, r, key-c-1), l = t;
    else split(t->l, l, t->l, key), r = t;
    upd_cnt(t);
}

void merge(Node *&t, Node *l, Node *r) {
    if (!l || !r) { t = l ? l : r; upd_cnt(t); return; }
    if (l->prior > r->prior) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    upd_cnt(t);
}

Node *root = nullptr;

vector <int> v;

void qr(Node *&t) {
    if (!t) return;
    qr(t->l);
    v.emplace_back(t->key);
    qr(t->r);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    srand(time(0));
    int n, q; cin >> n >> q;
    string s; cin >> s;
    for (int i = 0; i < n; i++) merge(root, root, new Node(i));
    while (q--) {
        int l, r; cin >> l >> r;
        Node *x, *y;
        split(root, root, x, l-1);
        split(x, x, y, r-l+1);
        merge(root, root, y);
        merge(root, root, x);
    }
    qr(root);
    for (auto &e : v) cout << s[e]; cout << '\n';
}