#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <pair <int,int>> a;
    for (int i = 0; i < n; i++) {
        int x, y;

        cin >> x >> y;
        a.push_back({y, x});
    }

    sort (a.begin(), a.end());

    int ans = 0, cur = 0;

    for (int i = 0; i < n; i++) {
        if (a[i].second >= cur) {
            ans++;
            cur = a[i].first;
        }
    }

    cout << ans;
}
