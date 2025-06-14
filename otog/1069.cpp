/*
    author  : PakinDioxide
    created : 22/05/2025 22:23
    task    : 1069
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e3+5;

#pragma GCC optimize("O2")
#pragma GCC target("avx2")

struct T {
    bool neg = 0;
    vector <short> s;
    bool operator<(const T &o) {
        if (neg != o.neg) return neg > o.neg;
        for (int i = mxN-1; i >= 0; i--) {
            if (s[i] < o.s[i]) return 1^neg;
            else if (s[i] > o.s[i]) return 0^neg;
        }
        return 0;
    }
    T operator+(const T &o) {
        if (neg == o.neg) {
            short t = 0;
            vector <short> ns(mxN);
            for (int i = 0; i < mxN; i++) ns[i] = (s[i] + o.s[i] + t) % 10, t = (s[i] + o.s[i] + t) / 10;
            return T{neg, ns};
        } else {
            short t = 0; bool nneg = 0;
            vector <short> a = s, b = o.s, ns(mxN);
            if (T{0, a} < T{0, b}) nneg = o.neg, swap(a, b);
            else nneg = neg;
            for (int i = 0; i < mxN; i++) {
                if (a[i] - b[i] - t < 0) ns[i] = 10 + a[i] - b[i] - t, t = 1;
                else ns[i] = a[i] - b[i] - t, t = 0;
            }
            return T{nneg, ns};
        }
    }
    void prt() {
        vector <short> ans = s;
        while (ans.size() > 1 && *ans.rbegin() == 0) ans.pop_back();
        reverse(ans.begin(), ans.end());
        if (neg) cout << '-';
        for (auto &e : ans) cout << e;
        cout << '\n';
    }
};

int n;
vector <T> a;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    a.resize(n);
    for (auto &e : a) {
        e.s.resize(mxN);
        string s; cin >> s;
        reverse(s.begin(), s.end());
        if (*s.rbegin() == '-') e.neg = 1, s.pop_back();
        else e.neg = 0;
        for (int i = 0; i < mxN; i++) e.s[i] = (i < s.size() ? s[i] - '0' : 0);
    }
    T mx, sum; mx.s.resize(mxN), sum.s.resize(mxN);
    mx.neg = 1;
    for (auto &e : mx.s) e = 9;
    for (auto &e : a) {
        T x = sum + e;
        if (x < e) sum = e;
        else sum = x;
        if (mx < sum) mx = sum;
    }
    mx.prt();
}