#include <bits/stdc++.h>
#include <chrono>
typedef long long ll;
#define nl "\n"
#define MOD (1000000000+7)
ll dp[5000][5000];

 
using namespace std;
 
void oj() { 
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void tv(int dp[]) {
    for (int i = 1; i<=100000; i++)
        if (dp[i]) cout << i << " ";
    cout << nl;
}

ll removalGame(vector<ll>& v, int l, int r, int turn) {
    if (l == r) {
        if (turn) return v[l];
        return 0;        
    }
    if (dp[l][r] != -1) return dp[l][r];
    if (turn)
        return dp[l][r] = max(v[l]+removalGame(v, l+1, r, turn^1), v[r]+removalGame(v, l, r-1, turn^1));
    return dp[l][r] = min(removalGame(v, l+1, r, turn^1), removalGame(v, l, r-1, turn^1));
}

 
 
int main()
{
    oj();
    int n; cin >> n;
    vector<ll> v(n, 0);
    memset(dp, -1, sizeof(dp));
    for (auto &i: v) cin >> i;

    cout << removalGame(v, 0, n-1, 1) << nl;
    return 0;
}