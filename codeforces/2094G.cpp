/*
    author  : PakinDioxide
    created : 14/04/2025 00:11
    task    : 2094G
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int q;
    cin >> q;
    ll sz = 0, sum1 = 0, sum2 = 0, total = 0;
    deque <ll> a, b;
    while (q--) {
        int t;
        cin >> t;
        if (t == 2) {
            swap(sum1, sum2);
            swap(a, b);
        } else if (t == 1) {
            sum1 = sum1 + total - a.back()*sz;
            sum2 = sum2 - total + b.front()*sz;
            a.emplace_front(a.back());
            b.emplace_back(b.front());
            a.pop_back();
            b.pop_front();
        } else {
            ll k;
            cin >> k;
            total += k;
            sz++;
            sum1 += sz*k;
            a.emplace_back(k);
            sum2 += total;
            b.emplace_front(k);
        }
        cout << sum1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
how do we do cyclic shift in o(1)

s = 2, we can sum += total - size*back + back
s = 3, we can sum += size*back

we can do it in both way? wow
*/