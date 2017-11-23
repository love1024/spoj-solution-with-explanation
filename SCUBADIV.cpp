#include<bits/stdc++.h>

using namespace std;

#define MAX 1005

int oxy[MAX],nit[MAX],w[MAX],dp[MAX][25][85];


int main() {
    int t,o,n,c;
    cin>>t;

    while(t--) {
        cin>>o>>n>>c;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<MAX;i++)
            oxy[i] = nit[i] = w[i] = 0;

        for(int i=0;i<c;i++) {
            cin>>oxy[i]>>nit[i]>>w[i];
        }



        for(int i=1;i<=c;i++) {
            for(int j=1;j<=o;i++) {
                for(int k=1;k<=n;k++) {
                    dp[i][j][k] = dp[i-1][j][k]
                    if(j <= oxy[i-1] && k< nit[i-1])
                        dp[i][j][k] = min(dp[i][j][k],w[i-1]);
                    else
                        dp[i][j][k] = min(dp[i][j][k],w[i-1] + dp[i-1][max(0,j-oxy[i-1])][max(0,k-nit[i-1])]);
                }
            }
        }

        cout<<dp[c][o][n]<<endl;
    }
}
