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
 
int dfs(int node, vector<vector<int>>& adj, vector<int>& numberOfSubordinates) {
    if ((int)adj[node].size() == 0) return 1;
    int count = 0;
    for (auto &i: adj[node])
        count += dfs(i, adj, numberOfSubordinates);
    numberOfSubordinates[node] = count;
    return count+1;

}
int main()
{
    oj();
    int n;
    cin >> n;
    vector<int> numberOfSubordinates(n+1, 0);
    vector<vector<int>> adj(n+1);

    for (int i = 2; i<=n; i++) {
        int x; cin >> x;
        adj[x].push_back(i);
    }

    dfs(1, adj, numberOfSubordinates);
    for (int i = 1; i<=n; i++)
        cout << numberOfSubordinates[i] << " ";
    cout << nl;
 
    
    return 0;
}