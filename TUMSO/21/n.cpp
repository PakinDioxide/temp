#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int a[n], b[n], ans = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int st = 0; st < n; st++) 
    {
        int sum = 0, cnt = n, idx = st;
        int ok = 1;
        while (cnt!=0) 
        {
            sum += b[idx];
            sum -= a[idx];
            idx++;
            idx %= n;
            //cout << sum << ' ';
            if (sum < 0) 
            {
                ok = 0; 
                break;
            }
            cnt--;
        }
        //cout<<"\n";
        ans += ok;
    }
    cout << ans;
}
/*
4
4 7 5 6
6 4 7 5
*/