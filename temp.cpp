// #include <bits/stdc++.h>
// #define ll long long

// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     ll a[n];
//     for (int i = 0; i < n; i++) cin >> a[i];
//     ll cnt = 0;
//     for (int i = 0; i < n; i++) {
//         int idx = lower_bound(a, a+n, 2*a[i]) - a;
//         cnt += n-idx;
//     }
//     cout << cnt << '\n';
// }

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
//ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;c

    vector <int> mochi(n);
    vector <int> sizewant(n);
    for(int i=0;i<n;i++){
        cin>>mochi[i];
        sizewant[i]=mochi[i]*2;
    }
    int indexsize=n-1;
    int ans=0;
    for(int i=n-1;i>=0;i--){
        
        for(indexsize;indexsize>=0;indexsize--){
            
            if(mochi[i]>=sizewant[indexsize]){
                
                ans=ans+indexsize+1;
                break;

            }

        }
        
        if(indexsize==-1){
            cout<<ans;
            return 0;
        }

    }
    cout<<ans;
}