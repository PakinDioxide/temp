#include <bits/stdc++.h>

using namespace std;

int bs(int lo, int hi, function<bool(int)> f) {
    lo--;

    while (lo < hi) {
        int mid = lo + (hi-lo+1)/2;

        if (f(mid)) {
            lo = mid;
        } else {
            hi = mid-1;
        }
    }

    return lo;
}

int main() {
    int n;
    long long k;

    cin >> n >> k;

    vector <int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    cout << bs(1, 2e9, [&](int x){
            long long need = 0;

            for (int i = (n-1)/2; i < n; i++) {
                need += max(0, x-a[i]);
                if (need > k) break;
            }

            return need <= k;
        });
}
