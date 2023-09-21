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
void tv(int dp[]) {
    for (int i = 1; i<=100000; i++)
        if (dp[i]) cout << i << " ";
    cout << nl;
}
 
 
int main()
{
    oj();
    int n, target; cin >> n >> target;
    memset(dp, 0, sizeof(dp));
    int coins[n+1];
    coins[0] = 0;
    for (int i = 1; i<=n; i++)
        cin >> coins[i];
 
    
    for (int i = 1; i<=n; i++) {
        dp[i][coins[i]]++;  
        for (int j =0; j<=1000000; j++) {
            dp[i][j] += dp[i-1][j];
            if (j > coins[i]) {
                dp[i][j] += dp[i][j-coins[i]];
                dp[i][j] = dp[i][j]%(1000000000+7);
            }
        }
    }
    cout << dp[n][target] << nl;
    // cout << "HELLO\n";
 
    
    return 0;
}