#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    unordered_map <int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x] = i+1;
    }
    while (q--) {
        int x;
        cin >> x;
        cout << mp[x] << '\n';
    }
}