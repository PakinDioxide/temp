#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

bool isValid(int n, vector<vector<int>>& adj, vector<int>& assignment) {
    
    for (int u = 0; u < n; u++) {
        if (assignment[u] == -1) continue;
        
        
        vector<int> connectedTypes(3, 0);
        
        for (int v : adj[u]) {
            if (assignment[v] == -1) continue;
            
            
            if (assignment[u] == assignment[v]) {
                return false;
            }
            
            
            connectedTypes[assignment[v]]++;
        }
        
        
        int ownType = assignment[u];
        int missingTypes = 0;
        
        for (int type = 0; type < 3; type++) {
            if (type != ownType && connectedTypes[type] == 0) {
                missingTypes++;
            }
        }
        
        if (missingTypes > 0) {
            return false;
        }
    }
    
    return true;
}

bool backtrack(int node, int n, vector<vector<int>>& adj, vector<int>& assignment, 
               vector<int>& typeCount, vector<int>& maxTypes) {
    
    if (node == n) {
        return isValid(n, adj, assignment);
    }
    
    
    for (int type = 0; type < 3; type++) {
        
        if (typeCount[type] < maxTypes[type]) {
            
            bool validAssignment = true;
            for (int neighbor : adj[node]) {
                if (assignment[neighbor] == type) {
                    validAssignment = false;
                    break;
                }
            }
            
            if (validAssignment) {
                
                assignment[node] = type;
                typeCount[type]++;
                
                
                if (backtrack(node + 1, n, adj, assignment, typeCount, maxTypes)) {
                    return true;
                }
                
                
                assignment[node] = -1;
                typeCount[type]--;
            }
        }
    }
    
    return false;
}

void solve(int caseNum) {
    int n, m, b, c, w;
    cin >> n >> m >> b >> c >> w;
    
    vector<vector<int>> adj(n);
    
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> assignment(n, -1);
    vector<int> typeCount(3, 0);
    vector<int> maxTypes = {b, c, w};
    
    
    
    for (int i = 0; i < n; i++) {
        
        for (int type = 0; type < 3; type++) {
            if (typeCount[type] < maxTypes[type]) {
                bool canAssign = true;
                
                
                for (int neighbor : adj[i]) {
                    if (assignment[neighbor] == type) {
                        canAssign = false;
                        break;
                    }
                }
                
                if (canAssign) {
                    assignment[i] = type;
                    typeCount[type]++;
                    break;
                }
            }
        }
    }
    
    
    if (!isValid(n, adj, assignment)) {
        
        fill(assignment.begin(), assignment.end(), -1);
        fill(typeCount.begin(), typeCount.end(), 0);
        
        backtrack(0, n, adj, assignment, typeCount, maxTypes);
    }
    cout << "Case #" << caseNum << ":" << endl;
    for (int i = 0; i < n; i++) {
        cout << assignment[i] << endl;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

}