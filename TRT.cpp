#include<bits/stdc++.h>

using namespace std;

int main() {

    //Take number of cows
    int n;
    cin>>n;

    //To store cows and intermediate results
    int arr[n];
    int dp[n][n];

    //Take cows treat
    for(int i=0;i<n;i++)
        cin>>arr[i];

    //Initialize the intermediate array
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dp[i][j] = 0;

    //Concept behind this is as follows
    //We have find use dp to find subproblem
    //First, Now we can reach to certain subproblem
    //By removing all remaining cows first. for example
    //in 6 1 5 5 to reach 6 1 we have to remove 5 5 first
    //So age for subproblem will be (Total - Subproblem size)
    //We can find subproblems from length 1
    //For length 1
    //It will be current treat * (n-1) which is by removing all cows its age
    //will be n - 1
    //For length > 1
    //We have to find maximum of two cases
    // - if we remove extreme left or if we extreme right
    for(int i=1;i<=n;i++) {
        for(int j=0;j<n-i+1;j++) {

            //End point of current subproblem
            int e = j+i-1;

            //If it is of length 1
            if(j == e)
                dp[j][e] = arr[j]*(n-i+1);
            else {

                //Else find maximum of given two cases removing first or last
                dp[j][e] = max(arr[j]*(n-i+1)+dp[j+1][e],arr[e]*(n-i+1)+dp[j][e-1]);
            }
        }
    }

    //Print out the result
    cout<<dp[0][n-1]<<endl;
}
