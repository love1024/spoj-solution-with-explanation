#include<bits/stdc++.h>

using namespace std;

int main() {

    //Take number of test cases
    int t,n;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take the number
        cin>>n;

        //All the numbers equal than half will get marked
        //So subtract them from total numbers
        cout<<(n - n/2)<<endl;
    }
}
