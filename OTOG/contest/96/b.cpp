/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    int a[n]; for (auto &e : a) cin >> e;
    int ans[n]; memset(ans, 0, sizeof(ans));
    stack <int> st; int ok = 0, ww[n], r = -1; memset(ww, 0, sizeof(ww));
    for (int i = 0; i < n; i++) {
        int L = 0;
        while (!st.empty() && st.top() >= max(0, i-a[i])) L = 1, st.pop();
        ans[i] = !L; r = -1;
        if (L) for (int j = i-1; j >= i-a[i]; j--) if (ans[j] == 0 && max(0, j-a[j]) >= max(0, i-a[i])) ans[j] = 1, r = max(r, min(n-1, j+a[j]));
        if (L) for (int j = i+1; j <= r; j++) ww[j] = 1;
        if (!ww[i]) st.emplace(i);
        if (!L) for (int j = i+1; j <= min(n, i+a[i]); j++) ww[j] = 1;
    }
    if (st.empty()) {
        cout << "YES\n";
        for (auto &e : ans) cout << (e ? 'R' : 'L');
        cout << '\n';
    } else cout << "NO\n";
}
/*
    consider the segment 0 0 0 .. 0 0 ( k zeros )
 */
