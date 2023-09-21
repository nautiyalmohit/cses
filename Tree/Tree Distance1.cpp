#include <bits/stdc++.h>
#include <chrono>
typedef long long ll;
#define nl "\n"
#define MOD (1000000000+7)
 
 
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
 
void dfs(int node, int height, vector<vector<int>>& adj, int vis[], vector<int>& depth) {
    vis[node] = 1;
    depth[node] = height;
    for (auto &i: adj[node])
        if (!vis[i]) {
            dfs(i, height+1, adj, vis, depth);
        }
}
int main()
{
    oj();
    int n, x, y; cin >> n;
    int vis[n+1];
    memset(vis, 0, sizeof(vis));
    vector<vector<int>> adj(n+1);
    vector<int> depth(n+1), distance(n+1, 0), distance2(n+1, 0);

    for (int i = 0; i<n-1; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);   
    }

    dfs(1, 0, adj, vis, depth);
    int a = 0, a_dist = -1;
    for (int i = 1; i<=n; i++) {
        if (depth[i] > a_dist) {
            a_dist = depth[i];
            a = i;
        }
    }
    memset(vis, 0, sizeof(vis));
    dfs(a, 0, adj, vis, distance);
    int b = 0, b_dist = -1;
    for (int i = 1; i<=n; i++) {
        if (distance[i] > b_dist) {
            b_dist = distance[i];
            b = i;
        }
    }
    memset(vis, 0, sizeof(vis));
    dfs(b, 0, adj, vis, distance2);
    for (int i = 1; i<=n; i++)
        cout << max(distance[i], distance2[i]) << " ";
    cout << nl;
    
    return 0;
}