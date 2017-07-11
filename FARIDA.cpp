#include<bits/stdc++.h>

using namespace std;

const int mx = 10005;
long long dp[mx];

int main() {

    //Number of test cases and monsters
    int t,n;
    cin>>t;

    //Loop over all test cases
    for(int k=1;k<=t;k++) {

        //Take number of monsters
        cin>>n;

        //Take coins for each monster
        vector<int> vec(n);
        for(int i=0;i<n;i++)
            cin>>vec[i];

        //Initialize for 1 monster
        dp[0] = vec.size()>0?vec[0]:0;

        //Loop over all monsters
        for(int i=1;i<n;i++) {

            //Choose max of current monster or last monsters sum
            //As in case of two monsters 10 3
            dp[i] = max(dp[i-1],(long long)vec[i]);
            for(int j=i-2;j>=0;j--) {

                //We can try to find adding current with all previous monsters
                //for finding maximum sum
                dp[i] = max(dp[i],vec[i]+dp[j]);
            }
        }

        //Print the result
        cout<<"Case "<<k<<": "<<dp[n-1]<<endl;
    }
}
