#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector <int> a;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        int add = 1;

        for (int j = 0; j < size(a); j++) {
            if (a[j] > t) {
                a[j] = t;
                add = 0;
                break;
            }
        }

        if (add) a.push_back(t);
    }

    cout << size(a);
}
