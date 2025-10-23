#include "particle.h"
#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
using std::vector;
using namespace std;
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N,Q;
    cin >> N >> Q;
    init(N);
    for(int i = 0;i < Q;i++) {
        int type,L,R;
        cin >> type >> L >> R;
        if(type==1) {
            int P; cin >> P;
            generateParticle(L,R,P);
        }
        else if(type==2) {
            cout << countSize(L,R) << '\n';
        }
        else {
            cout << bestPartition(L,R) << '\n';
        }
    }
    return 0;
}