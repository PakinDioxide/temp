#include <bits/stdc++.h>
 
using namespace std;
 
const int N=1e5+5;
int dsu[N];
 
int findpa(int u){
    if(dsu[u]==u) return u;
    return dsu[u]=findpa(dsu[u]);
}
 
int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int n,m,k; cin >> n >> m >> k;
    vector<pair<int,pair<int,int>>> v;
    for(int i=1 ; i<=n ; i++) dsu[i]=i;
    for(int i=1 ; i<=m ; i++){
        int a,b,w; cin >> a >> b >> w;
        v.push_back({w,{a,b}});
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int sz=n,i=0;
    while(sz!=k){
        int a=v[i].second.first;
        int b=v[i].second.second;
        if(findpa(a)==findpa(b)){
            i++;
            continue;
        }
        dsu[findpa(a)]=findpa(b);
        i++;
        sz--;
    }
    i--;
    cout << v[i].first << '\n';
}