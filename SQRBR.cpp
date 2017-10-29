#include<bits/stdc++.h>

using namespace std;

#define MAX 41
int arr[MAX];
long long dp[MAX][MAX];

long long recurse(int arr[],int i,int left,int n) {

    //If all brackets are over check if there are proper brackets
    if(i == n)
       return (left==0)?1:0;

    //If result is already known return it
    else if(dp[i][left])
        return dp[i][left];

    //If it is already open then simple go for next one
    if(arr[i] == 1)
        dp[i][left] = recurse(arr,i+1,left+1,n);
    else {
        long long r1,r2;
        r1=r2=0;
        //Put open bracket here
        r1 = recurse(arr,i+1,left+1,n);

        //Put close bracket here if there is previous
        //open bracket available
        if(left > 0)
            r2 = recurse(arr,i+1,left-1,n);

        //Store current result in array
        dp[i][left] =  r1+r2;
    }

    // return the result
    return dp[i][left];
}

int main() {

    //Take number of test cases
    int t,n,k,tmp;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take number of brackets and k
        cin>>n>>k;

        //Initialize array to 0
        memset(arr,0,sizeof(arr));
        memset(dp,0,sizeof(dp));

        //Take open brackets
        for(int i=0;i<k;i++) {
            cin>>tmp;
            arr[tmp-1] = 1;
        }

        //Recurse on all brackets
        cout<<recurse(arr,0,0,2*n)<<endl;
    }
}
