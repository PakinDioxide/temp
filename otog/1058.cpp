/*
    author  : PakinDioxide
    created : 17/04/2025 15:50
    task    : 1058
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mxN = 2e5+5;

ll n, q, w[mxN], p[mxN], c[mxN], cb[mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    w[0] = 0, p[0] = 0;
    for (int i = 0; i < n-1; i++) cin >> w[i], p[i+1] = w[i] + p[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = n-1; i >= 0; i--) cb[i] = cb[i+1] + w[i] * c[i+1];
    auto calc = [&] (ll k, ll x, ll y) { return cb[k] - cb[x] + c[k] * (p[y] - p[k]); };
    while (q--) {
        int x, y;
        cin >> x >> y;
        int l = 0, r = min(x, y);
        while (l < r) {
            int m1 = l + (r-l)/3;
            int m2 = r - (r-l)/3;
            if (calc(m1, x, y) > calc(m2, x, y)) l = m1+1;
            else r = m2-1;
        }
        cout << calc(l, x, y) << '\n';
    }
}

/*
def ternary_search_unimodal(arr):
    low = 0
    high = len(arr) - 1

    while low < high:
        mid1 = low + (high - low) // 3
        mid2 = high - (high - low) // 3

        if arr[mid1] < arr[mid2]:
            low = mid1 + 1
        else:
            high = mid2 - 1

    return arr[low]  # or return low for the index
*/