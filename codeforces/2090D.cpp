/*
    author  : PakinDioxide
    created : 23/03/2025 12:57
    task    : 2090D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <int> prime;

int isprime(int x) {
    if (x <= 1) return 0;
    if (x == 2) return 1;
    for (auto i : prime) {
        if (x % i == 0) return 0;
        if (i*i > x) break;
    }
    return 1;
}

int calc(int x, int i) {
    return ceil((float) x/i);
}

void solve() {
    int idx = 0, n;
    cin >> n;
    int a[n], sum = 2;
    set <int> st;
    for (int i = 1; i <= n; i++) if (i != 2) st.insert(i);
    a[1] = 2;
    for (int i = 2; i <= n; i++) {
        while (calc(sum+*st.begin(), i) > prime[idx]) idx++;
        auto it = st.lower_bound(i*(prime[idx]-1) + 1 - sum);
        if (it == st.end()) {
            a[i] = *(prev(st.end()));
            st.erase((prev(st.end())));
            sum += a[i];
            continue;
        }
        a[i] = *it;
        st.erase(it);
        sum += a[i];
    }
    sum = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';//, sum += a[i], cnt += isprime(ceil((float)(sum)/i));
    cout << '\n';
    // cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 2; i <= 100005; i++) if (isprime(i)) prime.push_back(i);
    int t;
    cin >> t;
    while (t--) solve();
}