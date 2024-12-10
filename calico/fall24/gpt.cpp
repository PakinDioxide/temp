#include <bits/stdc++.h>
using namespace std;

const int MAX_L = 1000000; // Adjust based on constraints
vector<int> phi(MAX_L + 1);
vector<long long> prefix_sum(MAX_L + 1);

void precompute_totient() {
    // Initialize phi values
    for (int i = 1; i <= MAX_L; i++) phi[i] = i;

    // Compute totient using a sieve
    for (int i = 2; i <= MAX_L; i++) {
        if (phi[i] == i) { // i is prime
            for (int j = i; j <= MAX_L; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }

    // Build prefix sum of phi
    for (int i = 1; i <= MAX_L; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + phi[i];
    }
}

void solve() {
    long long n;
    cin >> n;

    // Binary search to find the smallest l such that prefix_sum[l] >= n
    int l = lower_bound(prefix_sum.begin(), prefix_sum.end(), n) - prefix_sum.begin();

    // Offset within l
    long long offset = n - prefix_sum[l - 1];

    // Find the exact x
    for (int x = 1; x <= l; x++) {
        if (__gcd(l - x + 1, x) == 1) {
            offset--;
            if (offset == 0) {
                cout << x << ' ' << l - x + 1 << '\n';
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    precompute_totient();

    int t;
    cin >> t;
    while (t--) solve();
}
