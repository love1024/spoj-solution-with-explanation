#include<iostream>

using namespace std;

int main() {

    //Take number of test cases
    int t,n;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take number
        cin>>n;

        //If its odd print it and continue
        if(n&1) {
            cout<<n<<endl;
            continue;
        }

        //Else find binary representation and keep making new
        //number as it will be reverse of previous number
        int rev = 0;
        while(n > 0) {
            rev = 2*rev + (n%2);
            n /= 2;
        }

        //Print the result
        cout<<rev<<endl;
    }
}

