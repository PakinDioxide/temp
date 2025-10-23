#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int32_t main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int time;
    cin>>time;
    for(int ti=0;ti<time;ti++)
    {
        int n,m,temp;
        cin>>n>>m;
        vector<int> a,b;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            a.push_back(temp);
        }
        for(int i=0;i<m;i++)
        {
            cin>>temp;
            b.push_back(temp);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end(),greater<int>());
        int suma=0,sumb=0,maxi=0;
        for(int i=0;i<min(n,m);i++)
        {
            suma+=a[i];
            sumb+=b[i];
            if(maxi<sumb-suma)
                maxi=sumb-suma;
        }
        cout<<maxi<<"\n";
    }
}
/*
3
1 2
1
1 2
2 3
1 3
2 3 9
4 4
1 7 2 8
9 1 4 1

1
8
10
*/