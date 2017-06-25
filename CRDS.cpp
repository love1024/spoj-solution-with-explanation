#include<bits/stdc++.h>

using namespace std;

const int MOD = 1000007;

//Number of cards basically formed from two series
//2 1 4 2 6 3 8 ..
//First one is - 2 4 6 8 ... (n(n+1))
//Second one is -0 1 2 3 ... (n*(n-1)/2)
//So taking sum of both we get n*(3n+1)/2
int main() {

    //Number of test cases and level
    long long int t,n;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take the current level
        cin>>n;

        //Find the number of cards
        cout<<((n*(3*n+1))/2)%MOD<<endl;
    }
    return 0;
}
