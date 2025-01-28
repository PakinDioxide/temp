#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, id = 0;
    cin >> n;
    vector <tuple <int, int, int>> N, E;
    vector <tuple <int, int, char, int>> a(n);
    for (auto &[x, y, o, i] : a) {
        cin >> o >> x >> y, i = id++;
        if (o == 'N') N.emplace_back(x, y, i);
        else E.emplace_back(y, x, i);
    }
    sort(N.begin(), N.end());
    sort(E.begin(), E.end());
    int stp[n], ans[n];
    for (auto &e : ans) e = INT_MAX;
    for (auto &e : stp) e = 0;
    for (int i = 0; i < N.size(); i++) {
        
    }
}

/*
6
E 3 5
N 5 3
E 4 6
E 10 4
N 11 2
N 8 1
*/