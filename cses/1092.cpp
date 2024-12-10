#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = (n*(n+1))/2, k = sum / 2;
    if (sum&1) {cout << "NO"; return 0;}
    vector <int> a, b;
    int sa = 0, sb = 0, ok = 0;
    for (int i = 1; i <= n; i++) {
        if (sa + i < k && sa + 2*i + 1 > k) {
            sb += i;
            b.push_back(i);
            i++;
            sa += i;
        } else {
            sa += i;
            a.push_back(i);
        }
    }
    cout << a.size() << '\n';
    for (int i : a) cout << i << ' ';
    cout << '\n' << b.size() << '\n';
    for (int i : b) cout << i << ' ';
}