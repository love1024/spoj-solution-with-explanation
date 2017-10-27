#include<bits/stdc++.h>

using namespace std;

//Mod to take
#define MOD 1000000007

int main() {

    //Take number of test cases
    int t;
    cin>>t;

    //Loop over all test cases
    string str;
    while(t--) {

        //Take the string
        cin>>str;

        //array to store intermediate results
        long dp[str.length()+1];

        //To store last occurrence of the character initialize to -1
        int last[256];
        memset(last,-1,sizeof(last));
        dp[0] = 1;

        //Loop over all characters
        for(int i=1;i<=str.length();i++) {

            //Total subsequence increased by multiple of 2 with every character
            dp[i] = (2*dp[i-1])%MOD;

            //If this character is already found the subtract that subsequences
            //as that subsequences can be formed with this letters
            //MOD is added because result can become negative because of MOD
            if(last[str[i-1]] != -1)
                dp[i] = (dp[i] - dp[last[str[i-1]]-1] + MOD)%MOD;

            //Mark the position of current character
            last[str[i-1]] = i;
        }

        //Print the result
        cout<<dp[str.length()]<<endl;
    }
}
