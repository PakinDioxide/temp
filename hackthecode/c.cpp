#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool canPartition(const vector<int>& panels, vector<int>& set1, vector<int>& set2) {
    int totalSum = accumulate(panels.begin(), panels.end(), 0);
    
    // If the total sum is odd, we cannot split it into two equal parts
    if (totalSum % 2 != 0) {
        return false;
    }
    
    int target = totalSum / 2;
    int n = panels.size();
    
    // DP array to store if sum i is achievable
    vector<bool> dp(target + 1, false);
    vector<int> parent(target + 1, -1);  // to trace the subset
    
    dp[0] = true;  // Zero sum is always possible
    
    // Fill DP table
    for (int i = 0; i < n; ++i) {
        for (int j = target; j >= panels[i]; --j) {
            if (dp[j - panels[i]] && !dp[j]) {
                dp[j] = true;
                parent[j] = i;
            }
        }
    }
    
    // If it's not possible to reach the target, return false
    if (!dp[target]) {
        return false;
    }

    // Backtrack to find the panels in the first set
    int sum = target;
    while (sum > 0) {
        int index = parent[sum];
        set1.push_back(panels[index]);
        sum -= panels[index];
    }

    // The remaining panels go to the second set
    vector<bool> used(n, false);
    for (int p : set1) {
        for (int i = 0; i < n; ++i) {
            if (!used[i] && panels[i] == p) {
                used[i] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            set2.push_back(panels[i]);
        }
    }
    
    return true;
}

int main() {
    int C;
    cin >> C;  // Number of test cases
    
    for (int caseNum = 1; caseNum <= C; ++caseNum) {
        int N;
        cin >> N;  // Number of panels
        vector<int> panels(N);
        for (int i = 0; i < N; ++i) {
            cin >> panels[i];
        }
        
        vector<int> set1, set2;
        
        if (canPartition(panels, set1, set2)) {
            cout << "Case #" << caseNum << ":\n";
            cout << set1.size();
            for (int p : set1) {
                cout << " " << p;
            }
            cout << "\n";
            cout << set2.size();
            for (int p : set2) {
                cout << " " << p;
            }
            cout << "\n";
        } else {
            cout << "Case #" << caseNum << ": Impossible\n";
        }
    }
    
    return 0;
}
