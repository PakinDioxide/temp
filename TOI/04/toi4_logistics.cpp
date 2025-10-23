#include <bits/stdc++.h>

using namespace std;

vector <pair <int, float>> adj[28];
vector <tuple <char, char, float>> out;

int dfs(int u, int p) {
    vector <float> ve;
    int next = -1;
    for (auto [v, w] : adj[u]) {
        if (v == p) continue;
        ve.push_back(w);
        next = v;
    }
    sort(ve.begin(), ve.end());
    float med;
    if (ve.empty()) return 0;
    else if (ve.size()%2 == 0) med = (ve[(ve.size()/2)-1] + ve[(ve.size()/2)])/2;
    else med = ve[ve.size()/2];
    char a, b;
    if (u == 0) a = 'X';
    else if (u == 27) a = 'Y';
    else a = 'a' + u - 1;
    if (next == 0) b = 'X';
    else if (next == 27) b = 'Y';
    else b = 'a' + next - 1;
    out.emplace_back(a, b, med);
    if (next == 27) return 1;
    return dfs(next, u);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        char u, v;
        float w;
        cin >> u >> v >> w;
        int a, b;
        if (u == 'X') a = 0;
        else if (u == 'Y') a = 27;
        else a = u - 'a' + 1;
        if (v == 'X') b = 0;
        else if (v == 'Y') b = 27;
        else b = v - 'a' + 1;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }
    float ans = 0;
    if (dfs(0, -1)) {
        for (auto [a, b, w] : out) {printf("%c %c %.1f\n", a, b, w); ans += w;}
        printf("%.1f", ans);
    } else cout << "broken";
}