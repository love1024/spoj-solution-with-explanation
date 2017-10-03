#include<bits/stdc++.h>

using namespace std;

// Array to store temporary results
int dp[1005][1005];

//Find the maximum difference
void findDiff(int arr[],int n,int cur) {

    //Reset the array
    memset(dp,0,sizeof(dp));

    //Initialize the array with negative values
    //So that while we are at two length array
    //These values can get subtracted as greedy values
    //For example in 2 1, here if we choose 2 then -1 get subtracted
    //with result of 1
    for(int i=0;i<n;i++)
        dp[i][i] = -1*arr[i];

    //Traverse for each length
    for(int i=2;i<=n;i++) {

        //Traverse the whole array with this length
        for(int j=0;j+i-1<n;j++){

            //If it is odd length it is greedy strategy turn
            if(i&1){

                //If first is greater or equal go for first
                //if not than for second
                if(arr[j] >= arr[j+i-1])
                    dp[j][j+i-1] = dp[j+1][j+i-1]-arr[j];
                else
                    dp[j][j+i-1] = dp[j][j+i-2] - arr[j+i-1];
            } else {

                //If it is not greedy then choose maximum of two
                dp[j][j+i-1] = max(arr[j]+dp[j+1][j+i-1],arr[j+i-1]+dp[j][j+i-2]);
            }
        }
    }

    //Print the answer
    cout<<"In game "<<cur<<", the greedy strategy might lose by as many as "<<dp[0][n-1]<<" points."<<endl;
}


int main() {

    //Take number
    int n,cur=1;
    cin>>n;

    while(n != 0) {

        //Take input and print the result
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        findDiff(arr,n,cur);

        cin>>n;
        cur++;
    }
}
