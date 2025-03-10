#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int a[n];
        priority_queue <tuple <int, int, int>, vector <tuple <int, int, int>>, greater <tuple <int, int, int>>> q;
        for (int i = 0; i < n; i++) {scanf("%d", &a[i]); q.emplace(a[i], i > (n-1)/2 ? n-i - !(n&1) : i, i);}
        while (k--) {
            auto [x, y, z] = q.top();
            q.pop();
            a[z]++;
            q.emplace(a[z], y, z);
        }
        int jj = get<0>(q.top());
        int ans = jj * n - n + 1, l = 0, r = 0, t1 = 0, t2 = 0;
        for (int i = 0; i < n; i++) a[i] -= jj;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) l++;
            else break;
        }
        for (int i = n-1; i >= 0; i--) {
            if (a[i] > 0) r++;
            else break;
        }

        t1 += l;
        for (int i = 0; i < l; i++) a[i]--;
        int rr = 0;
        for (int i = n-1; i >= 0; i--) {
            if (a[i] > 0) rr++;
            else break;
        }
        t1 += rr;
        for (int i = 0; i < l; i++) a[i]++;

        t2 += r;
        for (int i = 0; i < r; i++) a[n-i-1]--;
        int ll = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) ll++;
            else break;
        }
        t2 += ll;

        ans += max(t1, t2);
        
        printf("%d\n", ans);
    }
}