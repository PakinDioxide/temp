#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int c = 0;
        vector <pair <int, int>> b(n);
        for (int i = 0; i < n; i++) scanf("%d", &b[i].second), b[i].first = b[i].second % k;
        sort(b.begin(), b.end());
        vector <vector <int>> v;
        vector <int> emp;
        int idx = -1, cc = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || b[i-1].first != b[i].first) {
                v.push_back(emp);
                idx++;
            }
            v[idx].push_back(b[i].second);
        }
        for (auto a : v) {
            if (a.size() % 2 == 1) cc++;
            if (cc == 2) {c = -1; break;}
            int ccc = 0, cccc = INT_MAX;
            for (int i = 0; i < a.size()-1; i += 2) ccc += (a[i+1] - a[i])/k;
            if (a.size() % 2 == 1) {cccc = 0; for (int i = 1; i < a.size(); i += 2) cccc += (a[i+1] - a[i])/k;}
            c += min(ccc, cccc);
        }
        printf("%d\n", c);
    }
}