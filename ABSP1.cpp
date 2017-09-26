#include<bits/stdc++.h>

using namespace std;

int main() {

    //Take number of test cases
    int t,n;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //take number
        cin>>n;

        //Take numbers
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        //Find sum of all numbers from end
        long long sum[n+1];
        memset(sum,0,sizeof(sum));
        for(int i=n-1;i>=0;i--) {
            sum[i] = sum[i+1] + arr[i];
        }

        //Find the result
        long long res = 0;
        for(int i=0;i<n-1;i++) {
            res += abs((n-i-1)*arr[i] - sum[i+1]);
        }

        //Print the answer
        cout<<res<<endl;
    }
}
