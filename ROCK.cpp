#include<bits/stdc++.h>

using namespace std;

int main() {

    //Take number of test cases
    int t,n,cnt;
    cin>>t;

    //While there is input
    string str;
    while(t--) {

        //Take length and number
        cin>>n>>str;

        int arr[n];
        for(int i=0;i<n;i++)
            arr[i] = str[i]=='0'?0:1;


        //Temporary storage for results
        int dp[n+1];
        memset(dp,0,sizeof(dp));

        //Traverse all array
        for(int i=0;i<n;i++) {

            //Make current result as previous
            dp[i+1] = dp[i];
            cnt = 0;

            //Now traverse array back and at each point
            //Check if whole combine group from j to i
            //is capable of selling, if yes then try
            //to find max of this group and previous
            //maximum we have already found from 0 to j-1
            for(int j=i;j>=0;j--) {
                cnt += (arr[j]==1?1:-1);
                if(cnt > 0)
                    dp[i+1] = max(dp[i+1],dp[j]+(i-j+1));
            }
        }

        //Print results
        cout<<dp[n]<<endl;
    }
}
