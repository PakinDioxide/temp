#include <bits/stdc++.h>

using namespace std;

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int a[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    // GET CYC
    vector <vector <int>> cyc;
    vector <int> vis(n+1), cycidx(n+1), dep(n+1);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int k = i;
        stack <int> st;
        while (!vis[k]) {
            vis[k] = 1;
            cycidx[k] = -1;
            st.emplace(k);
            k = a[k];
        }
        int cidx = cyc.size();
        if (cycidx[k] != -1) cidx = cycidx[k];
        else {
            cyc.push_back({}), dep[k] = 1;
            int sst = k;
            while (1) {
                dep[st.top()] = 1;
                cyc[cidx].push_back(st.top());
                cycidx[st.top()] = cidx;
                if (st.top() == sst) {st.pop(); break;}
                st.pop();
            }
        }
        while (!st.empty()) {
            dep[st.top()] = dep[k]+1;
            cyc[cidx].push_back(st.top());
            cycidx[st.top()] = cidx;
            k = st.top();
            st.pop();
        }
    }
    // FIND CYC
    int l = 0, r = cyc.size()-1, ccy = 0;
    while (l < r) {
        // cout << l << ' ' << r << '\n';
        int mid = (l+r)/2;
        cout << "ask ";
        vector <int> assk;
        for (int i = l; i <= mid; i++) {
            for (auto j : cyc[i]) assk.push_back(j);
        }
        cout << assk.size() << ' ';
        for (int i : assk) cout << i << ' ';
        cout << endl;
        cout.flush();
        string ans;
        cin >> ans;
        if (ans == "yes") r = mid;
        else l = mid+1;
    }
    ccy = l;
    // cout << ccy;
    vector <int> v = cyc[ccy];
    l = 1, r = 1;
    int ans = 0;
    for (int i : v) r = max(r, dep[i]);
    vector <int> aa;
    while (l < r) {
        // cout << l << ' ' << r << '\n';
        int mid = (l+r)/2;
        cout << "ask ";
        vector <int> assk;
        for (int i : v) {
            if (dep[i] <= mid) assk.push_back(i);
        }
        cout << assk.size() << ' ';
        for (int i : assk) cout << i << ' ';
        cout << endl;
        cout.flush();
        string ans;
        cin >> ans;
        if (ans == "yes") r = mid;
        else l = mid+1;
        if (r > 1) r--;
        if (l > 1) l--;
    }
    for (int i : v) if (dep[i] == l) aa.push_back(i);
    // cout << "DEP : " << l << '\n';
    l = 0, r = aa.size()-1;
    int brk = 0;
    while (l < r) {
        int mid = (l+r)/2;
        cout << "ask ";
        vector <int> assk;
        for (int i = l; i <= mid; i++) assk.push_back(a[i]);
        cout << assk.size() << ' ';
        for (int i : assk) cout << i << ' ';
        cout << endl;
        cout.flush();
        string ans;
        cin >> ans;
        if (ans == "yes") r = mid;
        else l = mid+1;
        for (int i = l; i <= r; i++) aa[i] = a[aa[i]];
    }
    // cout << "L " << l;
    cout << "answer " << aa[l];
    cout.flush();
}