#include <bits/stdc++.h>
#include <chrono>
typedef long long ll;
#define nl "\n"
#define MOD (1000000000+7)
int dp[100+1][1000000+1];
 
 
using namespace std;
 
void oj() { 
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void tv(vector<int>& v) {
    for (auto &i: v)
        cout << i << " ";
    cout << nl;
}
 
int dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[node] = 1;
    int count = 0;
    for (auto &i: adj[node])
        if (!vis[i]) {
            int Height = dfs(i, adj, vis, maxDiameter);
            maxDiameter = max(maxDiameter, Height+1+maxHeight);
            maxHeight = max(maxHeight, Height);
        }
    // cout << node << " " << maxHeight << nl; 

    return +1;

}
int main()
{
    oj();
    int n, x, y; cin >> n;
    vector<bool> vis(n+1, 0);
    vector<vector<int>> adj(n+1);

    for (int i = 0; i<n-1; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);   
    }

    dfs(1, adj, vis);
 
    
    return 0;
}