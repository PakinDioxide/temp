#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,a,b;
    cin >> n;
    int cnt[n]={0};
    for(int i=1; i<n; i++){
        cin >> a >> b;
        cnt[a-1]++;
        cnt[b-1]++;
    }
    int ans=cnt[0]-1;
    for(int i=1; i<n; i++) ans+=max(0,cnt[i]-2);
    cout << ans;
    return 0;
}