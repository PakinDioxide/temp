#include "Azzurro.h"
#include <bits/stdc++.h>

using namespace std;

std::vector<std::vector<int>> Azzurro(int N, int l, std::string S) {
    std::vector<std::vector<int>> x(N, std::vector<int>(N, 0));
    vector <int> a;
    for (auto &e : S) a.emplace_back(e == 'A');
    x[0][0] = a[0];
    x[N-1][N-1] = a[l-1];
    int it = 1;
    for (int k = 2; it < l-1 && k < 2*N; k++) {
        vector <pair <int, int>> v;
        for (int i = 0; i < N; i++) {
            int j = k-i;
            if (j < 0 || j >= N) continue;
            v.emplace_back(i, j);
            if (v.size() == 3) {
                map <int, int> cnt;
                for (auto &[xx, yy] : v) x[xx][yy] = a[it];
                v.clear();
                it++;
            }
        }
    }
    if (0 && l == 7) {
        cout << S << '\n';
        for (auto &E : x) {
            for (auto &e : E) cout << e << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
    return x;
}
