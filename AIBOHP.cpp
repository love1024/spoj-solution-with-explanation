#include<bits/stdc++.h>


using namespace std;

//Storage for intermediate results
int dp[6110][6110];

//Function to find minimum insertions
//The approach we are going to use is dynamic programming
//First we try to solve smaller sub problems such as of length 1,2...n;
//Consider this example fft
//For length 1
//Every string of length 1 is a palindrome so we store 0 for each single character
//For length 2
//Now if first and last character are equal then simple answer is 0
//else for example in 'ab' we can make it palindrome as 'aba' or 'bab'
//so we have two options in one we insert at last the first character and increase
//index of first character and in second we insert at first the last character
//and decrease index of last character
//we find the minimum of these two steps as we have already found the result for
//this smaller subproblems
//For length > 2
//IT will be similar to last step except when equal result will be equal to
//result of subproblem by removing these equal character
//for example in abca result will be of bc
int findMinInsertion(string &str) {

    //For one length it will simply be 0
    for(int i=0;i<str.length();i++)
        dp[i][i] = 0;

    //Find all length till the length of string
    for(int i=2;i<=str.length();i++) {

        //Now traverse all i length substring in string
        for(int j=0;j<str.length()-i+1;j++) {

            //Find end of current string
            int e = j + i - 1;

            //if char are equal and length is 2 we need 0 operations
            if(str[e] == str[j] && i == 2)
                dp[j][e] = 0;
            //else if length is greater than 2 operations are equal to inside subproblem
            else if(str[e] == str[j])
                dp[j][e] = dp[j+1][e-1];
            else
                //else if char are not equal either we can insert at last or start
                //so it will minimum of these two operations
                dp[j][e] = 1 + min(dp[j+1][e],dp[j][e-1]);
        }
    }

    //return result
    return dp[0][str.length()-1];
}
int main() {

    //Number of test cases
    int t;
    cin>>t;

    //Loop over all test cases
    string str;
    while(t--) {

        //Take input string
        cin>>str;

        //Make the storage first initialize to max
        for(int i=0;i<str.length()+1;i++)
            for(int j=0;j<str.length()+1;j++)
                dp[i][j] = INT_MAX;

        //Find the result
        cout<<findMinInsertion(str)<<endl;
    }

    return 0;
}
