#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <tuple <int, int, int>> E, N;
    for (int i = 0; i < n; i++) {
        char o;
        int x, y;
        cin >> o >> x >> y;
        if (o == 'E') E.emplace_back(y, x, i);
        else N.emplace_back(x, y, i);
    }
    sort(E.begin(), E.end()), sort(N.begin(), N.end());
    int stp[n], ans[n], idx = 0;
    memset(stp, 0, sizeof(stp));
    for (auto [x, y, i] : N) {
        while (idx < E.size()) {
            auto [yy, xx, ii] = E[idx++];
            int nx = 
        }
    }
}