#include <bits/stdc++.h>
#include <chrono>
typedef long long ll;
#define nl "\n"
#define MOD (1000000000+7)
int dp[5000][5000];

 
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
int editDistance(int nptr, int mptr, string& n, string& m) {
    // cout << nptr << " " << mptr << nl;
    if (nptr+1 == 0 || mptr+1 == 0) {
        return max(nptr+1, mptr+1);
    }
    if (dp[nptr][mptr] != -1) return dp[nptr][mptr];

    if (n[nptr] == m[mptr])
        return dp[nptr][mptr] = editDistance(nptr-1, mptr-1, n, m);
    int add = 1+editDistance(nptr, mptr-1, n, m),
        remove = 1+editDistance(nptr-1, mptr, n, m),
        replace = 1+editDistance(nptr-1, mptr-1, n, m);
    return dp[nptr][mptr] = min({add, remove, replace});
}
 
int main()
{
    oj();
    memset(dp, -1, sizeof(dp));
    string n, m; cin >> n >> m;
    int nsize = n.size(), msize = m.size();

    cout << editDistance(nsize-1, msize-1, n, m) << nl;

    return 0;
}