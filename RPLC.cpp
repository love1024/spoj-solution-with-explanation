#include<bits/stdc++.h>

using namespace std;

int main() {
    //Take number of test cases
    int t,n,x;
    cin>>t;

    //Loop over all test cases
    for(int j=1;j<=t;j++) {

        //Take input number
        cin>>n;

        //Take all numbers and add to current sum
        //and store minimum among these sums in min variable
        long long mn = 0,cur=0;
        for(int i=0;i<n;i++) {
            cin>>x;
            cur += x;
            mn = min(mn,cur);
        }

        //Print 1 +  this minimum value as this much power should
        //be required for continuous drinking
        cout<<"Scenario #"<<j<<": "<<(-1*mn + 1)<<endl;
    }
}
