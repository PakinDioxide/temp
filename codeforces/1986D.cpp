#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, ans = INT_MAX;
        scanf("%d", &n);
        string s;
        cin >> s;
        for (int o = 0; o < n-1; o++) {
            int a[n-1], sum = 0, zero = 0;
            vector <int> v;
            for (int i = 0; i < n; i++) {
                a[i - (i > o ? 1 : 0)] = s[i] - '0';
                if (i == o) a[i] *= 10, i++, a[i-1] += s[i] - '0';
                if (a[i - (i > 0 ? 1 : 0)] == 0) zero = 1;
            }
            if (zero) {ans = 0; break;}
            v.push_back(a[0]);
            for (int i = 1; i < n-1; i++) {
                if (v[v.size()-1] * a[i] <= v[v.size()-1] + a[i]) v[v.size()-1] *= a[i];
                else v.push_back(a[i]);
            }
            for (int i : v) sum += i;
            ans = min(ans, sum);
        }
        printf("%d\n", ans);
    }
}