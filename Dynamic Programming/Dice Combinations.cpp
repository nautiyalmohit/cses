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

 
 
int main()
{
    oj();
    int sum = 3; 
    cin >> sum;
    ll dp[sum+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i<=sum; i++)
        for (int j = 1; j<=6 && i-j>=0; j++) {
            dp[i] += dp[i-j];
            dp[i] %= MOD;
        }

    cout << dp[sum];
    return 0;
}