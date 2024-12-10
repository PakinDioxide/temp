#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("milkorder.in", "r", stdin);

    int n, m, k;

    cin >> n >> m >> k;

    vector <int> order(m);
    vector <pair <int, int>> want(k);

    for (int i = 0; i < m; i++) {cin >> order[i];}
    for (int i = 0; i < k; i++) {cin >> want[i].first >> want[i].second; want[i].second--;}

    vector <int> o(n);
    for (int i = 0; i < n; i++) o[i] = -1;

    for (int i = 0; i < k; i++) {
        o[want[i].second] = want[i].first;
    }

    int last = n-1;

    for (int i = m-1; i >= 0; i--) {
        int index = -1;

        for (int j = 0; j < n; j++) {
            if (o[j] == order[i]) {
                index = j;
                break;
            }
        }

        if (index == -1) {
            o[last] = order[i];
            for (int q = last-1; q >= 0; q--) {
                if (o[q] == -1) {
                    last = q;
                    break;
                }
            }
        } else {
            for (int q = index-1; q >= 0; q--) {
                if (o[q] == -1) {
                    last = q;
                    break;
                }
            }
        }
    }

    freopen("milkorder.out", "w", stdout);

    for (int i = 0; i < n; i++) {
        if (o[i] == -1 || o[i] == 0) {
            cout << i+1;
            break;
        }
    }
}
