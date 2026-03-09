#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int x, y, z; cin >> x >> y >> z;
    int n = x+z;
    vector <char> v;
    while (x > 0 && z > 0) {
        if (v.size() % 2 == 0) v.emplace_back('M'), x--;
        else v.emplace_back('T'), z--;
    }
    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

/*
MIT -
MTI
TIM -
TMI
IMT
ITM

I not center

if I > 2 error
*/