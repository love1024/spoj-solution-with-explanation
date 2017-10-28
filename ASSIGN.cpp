#include<bits/stdc++.h>

using namespace std;

//Array to store temporary results
long long dp[(1<<20)];

//Find set bits in the integer
int cntSetBits(int n) {
    int cnt = 0;
    while(n > 0) {
        if(n%2 != 0)
            cnt++;
        n /= 2;
    }
    return cnt;
}

int main() {

    //Take input
    int t,n,MAX;
    cin>>t;

    //While there is input
    while(t--) {

        //Take number
        cin>>n;

        //Store input
        vector< vector<int> > vec(n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                vec[i].resize(n);
                cin>>vec[i][j];
            }
        }

        //Initialize array to 0 & empty set to 1
        memset(dp,0,sizeof(dp));
        dp[0] = 1;

        //Find maximum number of subsets
        MAX = (1<<n);

        //Loop over all possible subsets
        for(int mask=0;mask<MAX-1;mask++) {

            //Find count of set bits and it will donate the its person
            int cnt = cntSetBits(mask);

            //Loop over the row and mark all the bits that we can set next
            for(int j=0;j<n;j++) {

                //If the current element is 1 and its bit is not already set
                //then set the current bit and add to it result of reaching it
                if(vec[cnt][j] == 1 && ((mask & (1<<j)) == 0))
                    dp[mask | (1<<j)] += dp[mask];
            }
        }

        //Print the possible way of reaching end result
        cout<<dp[MAX-1]<<endl;
    }
}
