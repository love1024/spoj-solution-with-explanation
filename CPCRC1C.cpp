#include<bits/stdc++.h>

// DIGIT DP

using namespace std;

//To store number in array
int arr[10];

//Each index , sum till index, restricted or not
long long dp[10][90][2];

//Convert number into array
void putInArray(int n,int arr[]) {
    int j = 9;
    while(n > 0) {
        arr[j] = n%10;
        n /= 10;
        j--;
    }
}

//We start with 1 digit then increase digits
//At each digit we decide whether we have to choose
// next digits from 0-9 or restricted it according to given
//number
long long solve(int i,long long sum,int arr[],bool flag) {

    //If this is last or result already found then return
    if(i == 10)
        return  sum;
    else if(dp[i][sum][flag] != -1)
        return dp[i][sum][flag];

    //Else put at this index digits according to given restrictive flag
    long long ret = 0;
    for(int j=0;j<10;j++) {

        //If there is restriction and we exceed its limit at current index
        //then break
        if(flag && j > arr[i])
            break;

        //Else there is restriction and this is last digit then following digits
        //will also be restricted
        else if(flag && j == arr[i])
            ret +=  solve(i+1,j+sum,arr,true);
        else
        //Else there is no restriction
            ret +=  solve(i+1,j+sum,arr,false);
    }

    //Store current result in dp and return it
    return dp[i][sum][flag] = ret;
}

long long sum(int a) {

    //Initialize array
    memset(arr,0,sizeof(arr));
    memset(dp,-1,sizeof(dp));

    //Putting in array
    putInArray(a,arr);

    //returning result
    return solve(0,0,arr,true);
}

int main() {

    //Take input
    int a,b;
    cin>>a>>b;

    //Print results
    while(a != -1 && b != -1) {

        long long s1 = sum(b);
        long long s2 = sum(a-1);
        cout<<s1-s2<<endl;
        cin>>a>>b;
    }
}
