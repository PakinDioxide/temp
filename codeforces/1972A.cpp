#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int n;
        scanf("%d", &n);
        vector <int> a(n), b(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) scanf("%d", &b[i]);
        int l = 0, r = 0, cnt = 0;
        while (r < n) {
            if (a[l] > b[r]) cnt++;
            else l++;
            r++;
        }
        printf("%d\n", cnt);
    }
}