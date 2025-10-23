#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    vector <int> d;
    d.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        int idx = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (idx == d.size()) d.push_back(a[i]);
        else d[idx] = a[i];
    }
    cout << d.size();
}
