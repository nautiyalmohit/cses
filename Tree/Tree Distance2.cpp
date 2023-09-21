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
 
ll findSubordinate(ll node, ll depth, vector<vector<ll>>& adj, ll vis[], vector<ll>& subordinates, vector<ll>& distance) {
    vis[node] = 1;
    ll count = 0;
    distance[1] += depth;
    for (auto &i: adj[node])
        if (!vis[i]) {
            count += findSubordinate(i, depth+1, adj, vis, subordinates, distance);
        }
    subordinates[node] = count;
    return count+1;
}
void dfs(ll node, ll parent, vector<vector<ll>>& adj, ll vis[], vector<ll>& subordinates, vector<ll>& distance) {
    vis[node] = 1;
    ll rem = (int)subordinates.size()-2-subordinates[node];
    if (node >= (int)subordinates.size())
        return;

    distance[node] = distance[parent] - subordinates[node]-1 + rem;
    for (auto &i: adj[node]) {
        if (!vis[i])
            dfs(i, node, adj, vis, subordinates, distance);
    }
}
int main()
{
    oj();
    ll n, x, y; cin >> n;
    ll vis[n+1];
    memset(vis, 0, sizeof(vis));
    vector<vector<ll>> adj(n+1);
    vector<ll> subordinates(n+1), distance(n+1, 0);

    for (int i = 0; i<n-1; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);   
    }

    findSubordinate(1ll, 0ll, adj, vis, subordinates, distance);
    memset(vis, 0, sizeof(vis));
    vis[1] = 1;
    for (auto &i: adj[1]) {
        if (!vis[i]) {
            dfs(i, 1ll, adj, vis, subordinates, distance);
        }
    }
    for (int i = 1; i<=n; i++)
        cout << distance[i] << " ";
    cout << nl;
    
   
    
    return 0;
}