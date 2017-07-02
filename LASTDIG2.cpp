#include<bits/stdc++.h>

using namespace std;

int main() {

    //Take number of test cases
    int t;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take base as temporary string and index as long long int
        string temp;
        long long int b;
        cin>>temp>>b;

        //Store in a the last digit of base
        int a = temp[temp.length()-1] - '0';

        //if index is 0 then answer will be 1
        if(b == 0) {
            cout<<1<<endl;
        } else if(a == 0) {

            //else if base is 0 answer will be 0
            cout<<0<<endl;
        } else {

            //else find modulus of index with 4 as digits repeat in cycle of 4
            b = b%4;

            //if it is multiple of 4 then it will repeat after 4 else it will
            //repeat after modulus
            b = (b == 0)?4:b;

            //store the result in res
            int res = a;

            //Multiply a with b times
            for(int i=0;i<b-1;i++)
                res = (res*a)%10;

            //Print the result
            cout<<res<<endl;
        }
    }
    return 0;
}
