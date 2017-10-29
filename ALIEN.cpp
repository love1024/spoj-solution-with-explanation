#include<bits/stdc++.h>

using namespace std;

int main() {

    //Take number of test cases
    int t,a,b;
    cin>>t;

    //While there is input
    while(t--) {

        //Take no of stations and max people
        cin>>a>>b;

        //Take people at stations
        int arr[a];
        for(int i=0;i<a;i++)
            cin>>arr[i];

        //Loop over all stations and use sliding window
        //Take only number of people required
        int sum = 0,len=0,strt=0,p=0,s=0;
        for(int i=0;i<a;i++) {

            //If we can add this station people
            //Add and increase length of sliding window
            if(sum+arr[i] <= b) {
                sum += arr[i];
                len++;
            } else {

                //If cannot add this station then subtract
                //the starting station people
                //Increase start to next stations
                //Decrease index so that we can next time try
                //same station and decrease length
                sum -= arr[strt];
                strt++,i--,len--;
            }

            //If current length is more then take it as result
            if(len > s) {
                s = len;
                p = sum;
            } else if(len == s && sum < p) {
                //If length is same but people are less
                p = sum;
            }
        }

        //Print the result
        cout<<p<<" "<<s<<endl;
    }
}
