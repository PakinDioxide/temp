#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define f first
#define s second
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num,te,mp,maxi=0;
    cin>>num;
    vector<pair<int,int>> v;
    for(int i=0;i<num;i++)
    {
        cin>>te>>mp;
        if(mp>maxi)
            maxi=mp;
        v.push_back({te,mp});
    }
    sort(v.begin(),v.end());
    int keb,ans=0;
    cout<<"\n";
    for(int i=1;i<=maxi;i++)
    {
        keb=lower_bound(v.begin(),v.end(),make_pair(i,-1))-v.begin();
        if(keb!=v.size())
        {
            ans++;
            cout<<v[keb].f<<" "<<v[keb].s<<"\n";
            v.erase(v.begin()+keb);
        }
    }
    cout<<ans;
}
/*
6
3 4
2 9
1 3
2 4
1 2
2 3
*/