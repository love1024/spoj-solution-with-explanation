#include<bits/stdc++.h>

using namespace std;

int main() {

    //Variables to store input
    int t,n,k;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take total kids and kids to take
        cin>>n>>k;

        //Take height of each kid
        vector<int> vec(n);
        for(int i=0;i<n;i++)
            cin>>vec[i];

        //Sort the height
        sort(vec.begin(),vec.end());

        //Make ans as MAX
        int ans = INT_MAX;

        //Loop over all heights
        for(int i=0;i<n;i++) {
            //While there are less kids the required continue
            if(i < k-1)
                continue;

            //Now take difference of extreme left and extreme right k kids height
            //As input is sorted extreme left will be smallest and extreme right will be largest
            //and check if it is minimum of previous result
            ans = min(ans,vec[i] - vec[i-k+1]);
        }

        //Print the result
        cout<<ans<<endl;
    }
}
