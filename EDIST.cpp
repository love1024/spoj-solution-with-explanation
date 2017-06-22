#include<bits/stdc++.h>

using namespace std;

//SAME as LCS problem with small change
//Three operations are there instead of two
//IN LCS we can remove any one character if they
//are not equal, Here we can replace also
//Adding a character in one string is same as deleting from
//Other so we will consider only deleting like LCS
//Other main thing is initial array which is
// 0 1 2 3 4
// 1 ...
// 2 ...
// 3 ...
// 4 ...
// To make string equal of length n and of empty length
// So we choose from three cases if two characters are not equal
// 1 + dp[i-1][j-1]  making character equal by replacing
// 1 + dp[i][j-1] Deleting character of String B
// 1 + dp[i-][j-1] Deleting character of String A
// Here 1 is of operations to perform
// If they are equal the
// dp[i-1][j-1] which is same as previous
int main() {

    //Taking number of test cases
    int t;
    cin>>t;

    //Loop over all test cases
    string A,B;
    while(t--) {

        //Taking both strings
        cin>>A>>B;

        //Finding length of both
        int m = A.length();
        int n = B.length();

        //Taking array for dp
        int dp[m+1][n+1];

        //Initializing array with 0 and certain values
        //As given above
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            dp[i][0] = dp[0][i] = i;


        //Find Minimum operations
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {

                //If character are equal it will cost no operations
                if(A[i-1] == B[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else {

                    //Else choose minimum with addition of 1 operation cost
                    dp[i][j] = 1 + min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
                }
            }
        }

        //Print the answer
        cout<<(dp[m][n])<<endl;
    }
}
