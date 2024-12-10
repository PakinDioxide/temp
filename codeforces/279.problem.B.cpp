#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;

    cin >> n >> t;

    int s[n];

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int r = 0, l = 0, c = 0, ans = 0;

    while (l < n && r < n) {
        while (r < n) {
            c += s[r++];

            if (c > t) {
                c -= s[--r];
                break;
            }
        }

        ans = max(ans, r - l);
        c -= s[l++];
    }

    cout << ans;
}
