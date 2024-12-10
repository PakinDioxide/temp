#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, mxx = 0, mix = INT_MAX, mxy = 0, miy = INT_MAX;
    scanf("%d %d", &n, &m);
    string a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#') {
                mxx = max(i, mxx);
                mix = min(i, mix);
                mxy = max(j, mxy);
                miy = min(j, miy);
            }
        }
    }
    mxx++, mxy++, mix++, miy++;
    int k = max(mxx+mix, mxy-miy)+1;
    printf("%d %d\n%.2f", (mxx+mix)/2, (mxy+miy)/2, (float) (k/2.0)*(k/2.0)*3.14);
}