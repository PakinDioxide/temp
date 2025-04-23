/*
    author  : PakinDioxide
    created : 15/04/2025 18:01
    task    : a1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 5e5+5;

int n, q;
ll a[mxN];
vector <bool> dp[40];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < 40; i++) dp[i].resize(n+5);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < 40; i++) for (int j = 1; j <= n; j++) dp[i][j] = dp[i][j-1] ^ ((a[j] & (1LL << i)) != 0);
    // cout << "ONE\n";
    // for (int i = 0; i < 3; i++) {
    //     for (int j = 1; j <= n; j++) cout << dp[1][i][j] << ' ';
    //     cout << '\n';
    // }
    // cout << "ZER\n";
    // for (int i = 0; i < 3; i++) {
    //     for (int j = 1; j <= n; j++) cout << dp[0][i][j] << ' ';
    //     cout << '\n';
    // }
    while (q--) {
        int l, r;
        cin >> l >> r;
        ll ans = 0;
        for (int i = 0; i < 40; i++) ans += ((dp[i][r] ^ dp[i][l-1]))*((r-l)%2)*(1LL << i);
        // for (int i = 0; i < 40; i++) {
        //     ans += (dp[0][i][r] - dp[0][i][l-1]) * (dp[1][i][r] - dp[1][i][l-1]) * (1LL << i);
        // }
        cout << ans << '\n';
    }
}
/*
we should compute each question in O(1) time

with O(n)/O(logN) precompute

we can find a_x ^ (a_1, a_n) in O(1) time, with O(n) precompute

let consider the sum of each bits in range a_l to a_r

O(n) solution for each query
sum = 0

for a_i : [l, r]
    for bits from 1 to 40
    if bits(a_i == 1) sum += sum(zr from l to r) * (1 << bits)
    else sum += sum(one from l to r) * (1 << bits)

let consider each bit

we will add the value each time bits(a_i == 1)
so if from a_l to a_r bits at that postion has k ones, so we will time k

but we need to devide it by 2 because we compute that i < j

oh we need to xor the value..

each bit of each index will appered (sz - 1) time..

010
011
100
001
*/