#include<bits/stdc++.h>

using namespace std;

//Find gcd of two numbers
int gcd(int a,int b) {
    if(a == 0)
        return b;
    return gcd(b%a,a);
}

int main() {

    //Take number of test cases
    int t,a,b;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take two numbers
        cin>>a>>b;

        //Find their gcd and divide both to find smallest form
        int GCD = gcd(a,b);

        a = a/GCD;
        b = b/GCD;

        //Ans will be their difference as one with slower speed is
        //completing the circle other one will meet him the difference of their
        //speed time
        cout<<abs(a-b)<<endl;
    }
}
