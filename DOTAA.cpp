#include<bits/stdc++.h>

using namespace std;

int main() {

    //Number of test cases,Heroes,Towers, and power of Tower
    int t,n,m,D;

    //Take number of test cases
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take variables
        cin>>n>>m>>D;

        //Take power of each hero
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        //Loop over all towers
        //Idx will represent the current hero
        //We will see how many towers current hero can cross
        int idx = 0,i=0;
        for(i=0;i<m && idx < n;i++) {

            //If current hero cannot cross this hero
            //Move to the next one,i-- is used as we do not
            //Want to next tower as we haven't crossed yet
            if(arr[idx]-D <= 0)
                i--,idx++;
            else
                //Else decrease power of this hero
                arr[idx] -= D;
        }

        //If we have crossed all towers print YES else NO
        if(i == m)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
