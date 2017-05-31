#include<bits/stdc++.h>

using namespace std;

int main() {

    //variable to store test cases
    int t;
    cin>>t;

    //loop over all test cases
    while(t--) {

        //variables to store coordinates
        int x,y;
        cin>>x>>y;

        //if and x and y are equal
        //or if x is 2 coordinate ahead
        //then this is our point
        if(x == y || x == y+2) {

            //if x coordinate is odd then
            //subtract 1 from sum else
            //print the sum
            cout<<(x+y - x%2==0?0:1)<<endl;
        } else {

            //else it is not in pattern
            cout<<"No Number"<<endl;
        }
    }
}
