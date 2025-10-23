#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll n;

vector <ll> a;

ll find_apple(ll index, ll n1, ll n2) {
    if (index == n) {
        return abs(n1-n2);
    }

    return min(find_apple(index+1, n1 + a[index], n2), find_apple(index+1, n1, n2 + a[index]));
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll aa;
        cin >> aa;
        a.push_back(aa);
    }

    cout << find_apple(0, 0, 0);
}
