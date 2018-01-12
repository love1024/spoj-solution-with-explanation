#include<bits/stdc++.h>

using namespace std;

int dp[110][110][2];

long long solve(int i,int n,int k,bool p) {
    if(k < 0)
        return 0;
    else if(i == n)
        return (k == 0);
    else if(dp[i][k][p] != -1)
        return dp[i][k][p];

    dp[i][k][p] = solve(i+1,n,k + (p?-1:0),true) + solve(i+1,n,k,false);
    return dp[i][k][p];
}

int main() {
    int t,i,n,k;
    cin>>t;

    while(t--){
        cin>>i>>n>>k;
        memset(dp,-1,sizeof(dp));
        cout<<i<<" "<<solve(0,n,k,false)<<endl;
    }
}
