#include <iostream>
#include <vector>
#include <queue>
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
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    for(int i=0;i<num;i++)
    {
        cin>>te>>mp;
        q.push({te,1});
        q.push({mp+1,-1});
        if(mp+1>maxi)
            maxi=mp+1;
    }
    cout<<"\n";
    int lob=0,hav=0;
    for(int i=1;i<=maxi;i++)
    {
        while(!q.empty()&&q.top().f==i)
        {
            hav+=q.top().s;
            q.pop();
            if(hav<0)
                hav=0;
        }
        if(hav>0)
        {
            lob++;
            hav--;
        }
        cout<<lob<<" "<<hav<<"\n";
    }
    cout<<lob;
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