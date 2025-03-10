#include <bits/stdc++.h>

using namespace std;

int n, a[5001];
long long c = 0;
map <int, int> cc;

void sub(int i, int ma) {
    if (i == n) {
        c = (c + ma) % 998244353;
        return;
    }
    sub(i+1, ma);
    cc[a[i]]++;
    sub(i+1, max(ma, cc[a[i]]));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    c = 0;
    sub(0, 0);
    cout << c << '\n';
}