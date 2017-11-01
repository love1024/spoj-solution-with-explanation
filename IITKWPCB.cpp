#include<bits/stdc++.h>

using namespace std;

//Find greater common divisor
long long gcd(long long a,long long b) {
    if(a == 0)
        return b;
    return gcd(b%a,a);
}

int main() {

    //Take number of test cases
    int t;
    cin>>t;

    //Loop over all test cases
    long long n;
    while(t--) {

        //Take the number
        cin>>n;

        //Check co prime and print
        for(long long i=n/2;i>=1;i--) {
            if(gcd(n,i) == 1) {
                cout<<i<<endl;
                break;
            }
        }
    }
}
