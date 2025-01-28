#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a, b;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        if (e < 0) a.push_back(e);
        else b.push_back(e);
    }
    for (int i : a) cout << i << ' ';
    for (int i : b) cout << i << ' ';
}