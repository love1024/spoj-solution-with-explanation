#include<bits/stdc++.h>

using namespace std;

#define MAX 1005

//Declare array
int oxy[MAX],nit[MAX],w[MAX],dp[MAX][25][85];


int main() {

    //Take number of test cases
    int t,o,n,c;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take oxygen,nitrogen and container
        cin>>o>>n>>c;

        //Initialize each to max
        for(int k=0;k<MAX;k++)
            for(int i=0;i<25;i++)
                for(int j=0;j<85;j++)
                    dp[k][i][j] = INT_MAX-1000;

        //Take inputs
        for(int i=0;i<MAX;i++)
            oxy[i] = nit[i] = w[i] = 0;

        for(int i=0;i<c;i++) {
            cin>>oxy[i]>>nit[i]>>w[i];
        }


        //When there is 0 oxygen and nitrogen we
        //can fulfill it with current container
        for(int i=1;i<=c;i++)
            dp[i][0][0] = w[i-1];

        //Loop over all items and check whether
        //we can form required values with items
        //from 1 to i
        for(int i=1;i<=c;i++) {

            //Check if we can form j oxygen and k nitrogen units with i items
            for(int j=0;j<=o;j++) {
                for(int k=0;k<=n;k++) {

                    //If current item can fulfill this oxygen and nitrogen
                    //Then take minimum of using this container or
                    //to choose container from previous values which can form
                    //this value
                    if(j <= oxy[i-1] && k<= nit[i-1])
                        dp[i][j][k] = min(dp[i-1][j][k],w[i-1]);
                    else
                    //Else we can take minimum of making nitrogen and oxygen
                    //from previous container or adding current and and taking
                    //rest from previous containers
                        dp[i][j][k] = min(dp[i-1][j][k],w[i-1] + dp[i-1][max(0,j-oxy[i-1])][max(0,k-nit[i-1])]);
                }
            }
        }

        //Print the results
        cout<<dp[c][o][n]<<endl;
    }
}
