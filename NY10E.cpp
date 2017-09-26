#include<bits/stdc++.h>

using namespace std;

int main() {

    //Take number of test cases
    int t,c,n;
    cin>>t;

    //Loop over all cases
    while(t--) {

        //Take current number
        cin>>c>>n;

        //Initialize array from 10 to 1
        long long arr[10];
        for(int i=0;i<10;i++)
            arr[i] = 10-i;

        //Start from 1 digit and go for full
        //for each increased digit find the the
        //number it can increase by adding 1,2,...9
        //at start of previous results
        for(int i=1;i<n;i++) {

            for(int i=0;i<10;i++) {
                for(int j=i+1;j<10;j++) {
                    arr[i] += arr[j];
                }
            }
        }

        //Print the result
        cout<<c<<" "<<arr[0]<<endl;
    }
}
