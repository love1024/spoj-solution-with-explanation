#include<bits/stdc++.h>

using namespace std;

//The problem here is unbounded knapsack or
//Knapsack with repetition
//As there are infinite times we can choose same
//resource so all the resources are available to us
//all the time, In classical knapsack we can use one
//item only one time. So we have to take 2d array to
//Store result for each case
//But in this case as all items are available we can
//Use only 1d array. for example while finding weight 1
//if we choose item no 3 no need to worry we can choose that
//again in later weights as resources are infinite.
//For each weight we find the minimum possible sum of coins
//we can get so use smaller subproblems while finding.
int main() {

    //Variables to store temporary data
    int t,E,F,n,W;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take weight of pigi bank, total weight and total number of coins
        cin>>E>>F>>n;

        //Find weight of coins
        W = F-E;

        //w - weight of each coin
        //v - value of each coin
        //dp - to store temporary result
        int w[n+1],v[n+1],dp[W+1];

        //Initialize dp to max value
        for(int i=0;i<=W;i++)
            dp[i] = INT_MAX;

        //Value of weight 0 will be 0
        dp[0] = 0;

        //Take values and weight of coins
        for(int i=0;i<n;i++)
            cin>>v[i]>>w[i];

        //Loop over all weights
        for(int i=0;i<=W;i++) {

            //Check for each coin
            for(int j=0;j<n;j++) {

                //If the current coin can be in weight of pigi bank
                //second check is used whether it can form sum of weight
                //required.for example we have weight 5 and coins 3,4.
                //No way we can make 5 using them so if it is not possible
                if(i >= w[j] && dp[i-w[j]] != INT_MAX)

                    //Choose the minimum of current value or
                    //Adding current value of coin and previous smaller
                    //subproblem
                    dp[i] = min(dp[i],dp[i-w[j]] + v[j]);
            }
        }

        //If we cant make weight then print impossible else answer
        if(dp[W] == INT_MAX)
            cout<<"This is impossible."<<endl;
        else
            cout<<"The minimum amount of money in the piggy-bank is "<<dp[W]<<"."<< endl;
    }

}
