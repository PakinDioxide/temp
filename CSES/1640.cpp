#include <bits/stdc++.h>

using namespace std;

struct compare {
 bool operator()(const pair<int, int>& value,
        const int& key)
 {
  return (value.first < key);
 }
 bool operator()(const int& key,
     const pair<int, int>& value)
 {
  return (key < value.first);
 }
};

int main() {
    int n, x;

    cin >> n >> x;

    vector <pair <int, int>> a;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back({t, i+1});
    }

    sort(a.begin(), a.end());

    int l = 0, r = 1;

    while (l < r && l < n) {
        while (r < n) {
            if (a[l].first+a[r].first > x) {
                r--;
                if (l >= r) {
                    r++;
                    break;
                }
            } else if (a[l].first+a[r].first == x) {
                cout << a[r].second << " " << a[l].second;
                return 0;
            }
            r++;
        }

        l++;
    }
    cout << "IMPOSSIBLE";
}
