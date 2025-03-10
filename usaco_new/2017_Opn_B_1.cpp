#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    int x, y, cnt = 0, c = 1;
    cin >> x >> y;
    if (x < y) {
        while (x+c < y) cnt += 6*c, c*=4;
        cnt += y-x;
    } else {
        cnt += 2*c;
        c*=2;
        while (x-c > y) cnt += 6*c, c*=4;
        cnt += x-y;
    }
    cout << cnt << '\n';
}