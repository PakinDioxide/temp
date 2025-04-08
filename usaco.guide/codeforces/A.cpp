#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    int x[n], y[n];

    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];

    long long max;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (max < (long long)(pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2))) max = (long long)(pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2));
        }
    }

    cout << max;
}
