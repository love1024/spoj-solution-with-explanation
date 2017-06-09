#include<bits/stdc++.h>

using namespace std;
/*
    Pattern in this program is that
    first is 192
    second is 250 more than first
    third is 250 more than second
    and so on...
*/
int main()
{
    //Number of test cases
    int t;
    cin>>t;

    //long long to store large result
    long long int n;

    //loop over all test cases
    while(t--) {

        //take number and display result
        cin>>n;
        cout<<(250*(n-1)+192)<<endl;
    }
    return 0;
}
