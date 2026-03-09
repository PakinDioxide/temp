#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    if (m == 0 && k == 1) {
        int c, d; cin >> c >> d;
        if (c+1 == d) for (int i = 0; i < n-1; i++) cout << i+1 << ' ' << i << '\n';
        else for (int i = 0; i < n-1; i++) cout << i << ' ' << i+1 << '\n';
    }
}

