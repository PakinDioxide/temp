/*
    author  : PakinDioxide
    created : 03/05/2025 21:58
    task    : D1_C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int a[2*n], dp[2*n], par[2*n], mx = 0, idx = 0;
    for (int i = 0; i < n; i++) cin >> a[i], a[i+n] = a[i];
    for (int i = 0; i < 2*n-1; i++) {
        dp[i] = 1;
        par[i] = i;
        for (int j = i-2; j >= 0; j--) if (a[i] <= a[j] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1, par[i] = j;
        if (dp[i] > mx) mx = dp[i], idx = i;
    }
    cout << mx << '\n';
    vector <int> ans;
    while (1) {
        ans.emplace_back(idx);
        if (idx == par[idx]) break;
        idx = par[idx];
    }
    reverse(ans.begin(), ans.end());
    // for (auto &e : ans) cout << e << ' ';
    // cout << '\n';
    int l = 0, r = n-1, id = 0, t = 1;
    cout << ans[0]+1 << ' ' << 1 << '\n';
    t = ans[0] + 1, id = 1;
    l += t, r += t;
    l++, r++, t++;
    for (int i = 1; i < mx; i++) {
        // need mx-i more jump
        int e = ans[i];
        while (l+1 < e && n-t-1 >= mx-i) l++, r++, t++;
        id = (e - l) + 1;
        // cout << e << ' ' 
        cout << t << ' ' << id << '\n';
        t++, l++, r++;
    }
}

/*
2 1 2 2 1
0 1 2 3 4
|   |  
  |   |
    |   |


choose 4 2 1 (1, 3, 7)
time = 2, id = 1

5 4 1 2 3 5 4 1 2
|       |
  |       |
    |       |
      |       |
        |       |
            
*/