#include<bits/stdc++.h>

using namespace std;

//ref- https://brilliant.org/wiki/finding-the-last-digit-of-a-power/


int main() {

    //variable to store number of test cases
    int t;
    cin>>t;

    //variable to store base and power a^b
    int a,b;

    //loop over all test cases
    while(t--) {

        //take base and power
        cin>>a>>b;

        //if power is 0 then it will be 1
        if(b == 0) {
            cout<<1<<endl;
        } else if(a == 0) {

            //else if base is 0 it will 0
            cout<<0<<endl;
        } else {

            //else using method that last
            //digit will repeat
            //after every cycle of 4
            b = (b%4==0)?4:b%4;

            //variable to store result
            //we only store last digit as
            //we only need it.
            int res = a = a%10;

            //loop through the remainder of
            //number after taking modulus
            //with 4
            for(int i=0;i<b-1;i++)
                res = (res*a)%10;

            //print the result
            //modulus 10 is used as if
            //loop will not run even once
            cout<<(res%10)<<endl;
        }
    }
}
