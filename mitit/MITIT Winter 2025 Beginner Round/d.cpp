#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <tuple <int, vector <int>, int>> a(n);
    for (int i = 0; i < n; i++) {
        get<1>(a[i]).resize(k);
        for (int j = 0; j < k; j++) cin >> get<1>(a[i])[j], get<0>(a[i]) += get<1>(a[i])[j];
        get<2>(a[i]) = i+1;
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (get<1>(a[i-1])[j] > get<1>(a[i])[j]) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << get<2>(a[i]) << ' ';
    cout << '\n';
}