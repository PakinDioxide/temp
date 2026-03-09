#include "transfer.h"
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> get_attachment(vector<int> a) {
    int n = a.size();
    vector <int> v;
    int it = 0;
    int b[513]; memset(b, 0, sizeof(b));
    for (int i = 0; (1 << i) <= 512; i++) b[(1 << i)] = 1;
    for (int i = 0; it < n; i++) {
        if (b[i+1]) v.emplace_back(0);
        else v.emplace_back(a[it++]);
    }
    vector <int> ans;
    for (int i = 0; (1 << i) <= v.size(); i++) {
        for (int j = 0; j < v.size(); j++) if ((j+1) & (1 << i)) v[(1<<i)-1] ^= v[j];
        ans.emplace_back(v[(1<<i)-1]);
    }
    return ans;
}

vector<int> retrieve(vector<int> v) {
    int cnt = 0;
    for (int i = 0; (1 << i) <= v.size(); i++) cnt++;
    vector <int> a, ks;
    for (int i = 0; i < (int) v.size()-cnt; i++) a.emplace_back(v[i]);
    for (int i = (int) v.size()-cnt; i < v.size(); i++) ks.emplace_back(v[i]);
    vector <int> V;
    int ia = 0, ik = 0;
    int b[513]; memset(b, 0, sizeof(b));
    for (int i = 0; (1 << i) <= 512; i++) b[(1 << i)] = 1;
    for (int i = 0; i < v.size(); i++) {
        if (b[i+1]) V.emplace_back(ks[ik++]);
        else V.emplace_back(a[ia++]);
    }
    swap(v, V);
    int k = 0;
    for (int i = 0; (1 << i) <= v.size(); i++) {
        int kk = 0;
        for (int j = 0; j < v.size(); j++) if ((j+1) & (1 << i)) kk ^= v[j];
        k |= (kk << i);
    }
    k--;
    if (k >= 0) v[k] ^= 1;
    a.clear();
    for (int i = 0; i < v.size(); i++) {
        if (!b[i+1]) a.emplace_back(v[i]);
    }
    return a;
}
