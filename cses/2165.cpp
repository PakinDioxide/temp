#include <bits/stdc++.h>

using namespace std;

vector <pair <int, int>> v;

void mov(int n, int l, int m, int r) {
    if (n == 0) return;
    mov(n-1, l, r, m);
    v.emplace_back(l, r);
    mov(n-1, m, l, r);
}

int main() {
    int n;
    cin >> n;
    mov(n, 1, 2, 3);
    cout << v.size() << '\n';
    for (auto [x, y] : v) cout << x << ' ' << y << '\n';
}