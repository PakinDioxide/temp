#include <bits/stdc++.h>

using namespace std;

int prime[200005], l = 0;

vector <int> adj[200005];

void addedge(int p,int x,int y,int t){
    if(t==l){
        adj[x].push_back(y);
        return;
    }
    if(p&(1<<t)){
        addedge(p,x|(1<<t),y,t+1);
        addedge(p,x,y|(1<<t),t+1);
    } else{
        addedge(p,x,y,t+1);
        addedge(p,x|(1<<t),y|(1<<t),t+1);
    }
}

int main() {
    int t, n = 0;
    scanf("%d", &t);
    int na[t];
    for (int i = 0; i < t; i++) {
        scanf("%d", &na[i]);
        n = max(na[i], n);
    }
for(int i=0; i<20; i++) if(n&(1<<i)) l=i;
    l++;
    prime[0] = prime[1] = 1;
    for (int i = 2; i <= 200003; i++) {
        if (prime[i]) {
            // for (int j = 1; j < i && j <= n; j++) if (i ^ j <= n) adj[j].push_back(i ^ j);
            addedge(i, 0, 0, 0);
            continue;
        }
        for (int j = 2; j*i <= 200003; j++) prime[i*j] = 1;
    }
    int k = 1;
    vector <int> c(n+1), kk(n+1);
    c[1] = kk[1] = 1;
    for (int i = 2; i <= n; i++) {
        vector <int> cl(k + 2);
        int mk = 1;
        for (int j : adj[i]) {
            if (j > n) continue;
            cl[c[j]] = 1;
            while (cl[mk]) mk++;
        }
        c[i] = mk;
        k = max(k, mk);
        kk[i] = k;
    }
    for (int i : na) {
        printf("%d\n", kk[i]);
        for (int j = 1; j <= i; j++) printf("%d ", c[j]);
        printf("\n");
    }
}