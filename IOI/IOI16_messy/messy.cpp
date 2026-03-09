
#include "messy.h"
#include <bits/stdc++.h>

using namespace std;

static int ans[128], n;

void dnc1(int l, int r) {
    if (r - l == 1) return;
    int m = l + (r-l)/2;
    string s;
    for (int i = 0; i < l; i++) s += '1';
    for (int i = l; i < r; i++) s += '0';
    for (int i = r; i < n; i++) s += '1';
    for (int i = l; i < m; i++) {
        s[i] = '1';
        add_element(s);
        s[i] = '0';
    }
    dnc1(l, m), dnc1(m, r);
}

void dnc2(int l, int r, vector <int> A) {
    if (r - l == 1) { ans[l] = A[0]; return; }
    int m = l + (r-l)/2;
    string s;
    for (int i = 0; i < n; i++) s += '1';
    for (auto &e : A) s[e] = '0';
    vector <int> L, R;
    for (auto &e : A) {
        s[e] = '1';
        if (check_element(s)) L.emplace_back(e);
        else R.emplace_back(e);
        s[e] = '0';
    }
    dnc2(l, m, L), dnc2(m, r, R);
}

vector <int> restore_permutation(int N, int w, int r) {
    n = N;
    dnc1(0, n);
    compile_set();
    vector <int> X; for (int i = 0; i < n; i++) X.emplace_back(i);
    dnc2(0, n, X);
    vector <int> rst(n);
    for (int i = 0; i < n; i++) rst[ans[i]] = i;
    return rst;
}

/*
check which N/2 bits 
*/