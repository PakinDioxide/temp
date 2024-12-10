#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    pair <long long, long long> a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a, a+n);
    for (int i = 0; i < n && a[i].first < k; i++) {
        long long f1 = k - a[i].first;
        for (int j = i+1; j < n && a[j].first < f1; j++) {
            long long f2 = f1 - a[j].first;
            int l = j+1, r = n-1;
            while (l < r) {
                int mid = (l+r)/2;
                if (a[mid].first == f2) {
                    l = r = mid;
                } else if (a[mid].first < f2) {
                    l = mid+1;
                } else r = mid-1;
            }
            if (a[l].first == f2) {
                cout << a[i].second << ' ' << a[j].second << ' ' << a[l].second;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
}