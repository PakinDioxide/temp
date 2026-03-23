#include "Bordeaux.h"
#include <bits/stdc++.h>

using namespace std;

std::string Bordeaux(int N, int l, std::vector<std::vector<int>> x) {
    if (0 && l == 7) {
        for (auto &E : x) {
            for (auto &e : E) cout << e << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
    vector <int> a(l);
    a[0] = !x[0][0];
    a[l-1] = !x[N-1][N-1];
    int it = 1;
    for (int k = 2; it < l-1 && k < 2*N; k++) {
        vector <pair <int, int>> v;
        for (int i = 0; i < N; i++) {
            int j = k-i;
            if (j < 0 || j >= N) continue;
            v.emplace_back(i, j);
            if (v.size() == 3) {
                map <int, int> cnt;
                for (auto &[xx, yy] : v) cnt[x[xx][yy]]++;
                for (auto &[p, q] : cnt) if (q >= 2) a[it] = p;
                v.clear();
                it++;
            }
        }
    }
    string s;
    for (auto &e : a) s += (e ? "A" : "B");
    while (s.size() < l) s += "A";
	return s;
}
