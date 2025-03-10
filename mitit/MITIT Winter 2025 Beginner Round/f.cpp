#include <bits/stdc++.h>
#define ll long long

using namespace std;

int solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size();
    vector <int> pe, po, qe, qo;
    for (int i = 0; i < n; i++) {
        if (a[i] == 'A' && i % 2 == 0) pe.push_back(i);
        else if (a[i] == 'A') po.push_back(i);
        if (b[i] == 'A' && i % 2 == 0) qe.push_back(i);
        else if (b[i] == 'A') qo.push_back(i);
    }
    int cnt = 0;
    if (pe.size() != qe.size() || po.size() != qo.size() || a.size() < 3) return -1;
    for (int i = 0; i < pe.size(); i++) cnt += abs(pe[i] - qe[i])/2;
    for (int i = 0; i < po.size(); i++) cnt += abs(po[i] - qo[i])/2;
    return cnt;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) cout << solve() << '\n';
}

/*
Analysis
is swaping two different character []_[]
*/