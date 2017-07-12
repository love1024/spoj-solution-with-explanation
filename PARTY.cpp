#include<bits/stdc++.h>

using namespace std;

//Storage for temporary results
int dp[101][501];


int main() {

    //Take budget and number of parties
    int b,n;
    cin>>b>>n;

    //While there is input
    while(b != 0 && n != 0) {

        //To store fee and fun
        vector<int> fee(n);
        vector<int> fun(n);

        //Take fee and fun of each party
        for(int i=0;i<n;i++)
            cin>>fee[i]>>fun[i];

        //Initialize storage to 0
        for(int i=0;i<=n;i++)
            for(int j=0;j<=b;j++)
                dp[i][j] = 0;

        //The approach is of two parts
        //CANNOT ADD
        //If we cannot add this party as its budget is more than given
        //then the result will be same as previous party we visited
        //CAN ADD
        //The we check for the max of two cases
        // 1 - Previous parties fun
        // 2 - Add fun of this party and parties we can get after subtracting budget
        // from given one (We have already found as is of subproblem)
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=b;j++) {

                //If we can add this party to fun the find max of above two cases
                if(fee[i-1] <= j)
                    dp[i][j] = max(fun[i-1]+dp[i-1][j-fee[i-1]],dp[i-1][j]);
                else

                    //Else fun will be of previous parties
                    dp[i][j] = dp[i-1][j];
            }
        }

        //To find minimum budget we check last row
        //That can we get same fun as last at lesser budget
        //We start from 1 and check till W if we can find same as
        //Our best budget
        int ans = -1;
        for(int i=1;i<=b;i++) {
            if(dp[n][i] == dp[n][b]) {
                ans = i;
                break;
            }
        }

        //Print the result
        cout<<ans<<" "<<dp[n][b]<<endl;

        //Take another input
        cin>>b>>n;
    }
    return 0;
}
