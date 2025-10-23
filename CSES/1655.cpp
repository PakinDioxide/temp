#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int trie[6000005][2], idx = 1;
 
void insert(ll x, int cnt, int node) {
    if (cnt == -1) return;
    int k = ((x & (1 << cnt)) > 0);
    if (trie[node][k] == 0) trie[node][k] = ++idx;
    insert(x, cnt-1, trie[node][k]);
}
 
ll find(ll x, int cnt, int node) {
    if (cnt == -1) return 0;
    int k = ((x & (1 << cnt)) > 0);
    if (trie[node][k] == 0) return find(x, cnt-1, trie[node][!k]) + ((!k) << cnt);
    else return find(x, cnt-1, trie[node][k]) + (k << cnt);
}
 
int main() {
    int n;
    cin >> n;
    ll a[n+1];
    a[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] ^= a[i-1], insert(a[i], 30, 1);
    ll mx = 0, mxN = 0;
    insert(0, 30, 1);
    for (int i = 0; i <= 30; i++) mxN |= (1 << i);
    for (int i = 1; i <= n; i++) mx = max(mx, a[i] ^ find(mxN ^ a[i], 30, 1));
    cout << mx << '\n';
}