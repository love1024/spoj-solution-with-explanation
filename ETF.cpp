#include<bits/stdc++.h>

using namespace std;

//https://www.topcoder.com/community/data-science/data-science-tutorials/prime-numbers-factorization-and-euler-function/

//Function to find totient using above tutorial
int findTotient(int n) {
    int result = n;
    for(int i=2;i*i<=n;i++) {
        if(n%i == 0)
            result = result - result/i;
        while(n%i == 0)
            n = n/i;
    }
    if(n > 1)
        result = result - result/n;
    return result;
}


int main() {

    //Number of test cases and number
    int t,n;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take number and find totient
        cin>>n;
        cout<<findTotient(n)<<endl;
    }
}
