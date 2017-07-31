#include<bits/stdc++.h>

using namespace std;

//Find greatest common divisor of two numbers
long long gcd(long long a,long long b) {
    if(a == 0)
        return b;
    return gcd(b%a,a);
}


int main() {

    //Number of test cases and two numbers
    long long t,A,B;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take two numbers
        cin>>A>>B;

        //Find their GCD to find LCM
        long long GCD = gcd(A,B);

        //Find LCM from equation A*B = LCM*GCD
        long long LCM = (A*B)/GCD;

        //print the result just dividing lcm by numbers
        cout<<(LCM/A)<<" "<<(LCM/B)<<endl;
    }
}
