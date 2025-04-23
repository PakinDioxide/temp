/*
    author  : PakinDioxide
    created : 16/04/2025 08:32
    task    : 2022_Jan_G_1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 105, mxH = 1005;
const ll mod = 1e9+7;

ll n, dp[2][2*mxN*mxH], a[mxN], offset = mxN*mxH;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll ans = 0;
    for (int value = 0; value <= mxH; value++) {
        memset(dp, 0, sizeof(dp));
        dp[0][offset] = 1;
        for (int sumdiff = 1; sumdiff < 2*mxN*mxH; sumdiff++) dp[0][sumdiff] += dp[0][sumdiff-1];
        // cout << "value : " << value << '\n';
        for (int i = 1; i <= n; i++) {
            for (int sumdiff = 0; sumdiff < 2*mxN*mxH; sumdiff++) dp[i&1][sumdiff] = 0;
            // // TLE
            // for (int e = 0; e <= a[i]; e++) {
            //     if (e < value) continue;
            //     int diff = (i % 2 == 1 ? (e-value) : -(e-value));
            //     // cout << i << ' ' << diff << '\n';
            //     // for (int sumdiff = 0; sumdiff < 2*mxN*mxH; sumdiff++) if (sumdiff - diff >= 0 && sumdiff - diff < 2*mxN*mxH) dp[i&1][sumdiff] += dp[!(i&1)][sumdiff - diff], dp[i&1][sumdiff] %= mod;
            //     if (i % 2 == 1) {for (int sumdiff = offset; sumdiff < 2*mxN*mxH; sumdiff++) if (sumdiff - diff >= 0 && sumdiff - diff < 2*mxN*mxH) dp[i&1][sumdiff] += dp[!(i&1)][sumdiff - diff], dp[i&1][sumdiff] %= mod;}
            //     else {for (int sumdiff = 0; sumdiff <= offset; sumdiff++) if (sumdiff - diff >= 0 && sumdiff - diff < 2*mxN*mxH) dp[i&1][sumdiff] += dp[!(i&1)][sumdiff - diff], dp[i&1][sumdiff] %= mod;}
            // }

            // PREFIX SUM
            if (a[i] < value) continue;
            // int mindiff = 0, maxdiff = a[i] - value;
            int diff = a[i] - value;
            if (i % 2 == 1) {for (int sumdiff = offset; sumdiff < 2*mxN*mxH; sumdiff++) dp[i&1][sumdiff] += dp[!(i&1)][sumdiff] - dp[!(i&1)][max(0, sumdiff - diff-1)], dp[i&1][sumdiff] += mod, dp[i&1][sumdiff] %= mod;}
            else {for (int sumdiff = 0; sumdiff <= offset; sumdiff++) dp[i&1][sumdiff] += dp[!(i&1)][min(2*mxN*mxH-1, sumdiff + diff)] - dp[!(i&1)][max(0, sumdiff-1)], dp[i&1][sumdiff] += mod, dp[i&1][sumdiff] %= mod;}
            
            // if (i % 2 == 1) {for (int sumdiff = offset; sumdiff < 2*mxN*mxH; sumdiff++) if (sumdiff - diff >= 0 && sumdiff - diff < 2*mxN*mxH) dp[i&1][sumdiff] += dp[!(i&1)][sumdiff - diff], dp[i&1][sumdiff] %= mod;}
            // else {for (int sumdiff = 0; sumdiff <= offset; sumdiff++) if (sumdiff - diff >= 0 && sumdiff - diff < 2*mxN*mxH) dp[i&1][sumdiff] += dp[!(i&1)][sumdiff - diff], dp[i&1][sumdiff] %= mod;}

            // cout << "I " << i << '\n';
            // for (int j = offset - 20; j <= offset+20; j++) cout << dp[i&1][j] << ' ';
            // cout << '\n';

            for (int sumdiff = 1; sumdiff < 2*mxN*mxH; sumdiff++) dp[i&1][sumdiff] += dp[i&1][sumdiff-1], dp[i&1][sumdiff] %= mod;
        }
        if (value > 11) break;
        ans += (dp[n&1][offset] - dp[n&1][offset-1] + mod) % mod, ans += mod, ans %= mod;
        if (n % 2 == 0) break;
    }
    cout << ans << '\n';
}

/*
no prefix sum

3
9 11 7
I 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 
I 2
0 0 0 0 0 0 0 0 0 1 2 3 4 5 6 7 8 9 10 10 10 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
I 3
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 65 60 54 47 39 30 20 10 0 0 0 0 0 0 0 0 0 0 0 0 0
3
9 11 7
I 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 
I 2
0 0 0 0 0 0 0 0 0 1 2 3 4 5 6 7 8 9 9 9 8 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
I 3
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 56 50 43 35 26 17 8 0 0 0 0 0 0 0 0 0 0 0 0 0 0

prefix sum
*/

/*
it will be possible when..

let choose a number a[1] = x

then if a[2] = x+5

a[3] = x+5+diff

if end at a[3], then diff must equal to zero

then we start a new one?

dp[i][value][diff] ?

but it would cause memory limit exceed

we can optimize the memory by using dp[2][value][diff]

the last one cant be new

can we use mcm?

it should be O(n(mxH)^2)?

[8, 10, 5] -> 3
[5,  7, 2]

it is a chain reaction

so the dif of a[1] - a[0]
then a[2] - a[1]

and so on

so if n is even, if it is poissilbe to convert it, then it can always be zero

else if n is odd, it can't

so we can do dp[n][same value][value]

no?

diffn - (diffn-1 - (diffn-2 - ... (diff2-diff1))) must equal to zero

dp[n][samevalue][sumdiff]

*/