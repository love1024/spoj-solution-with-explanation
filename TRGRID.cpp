#include<bits/stdc++.h>

using namespace std;

/*
    The idea here is that at every complete loop
    max 2 of row and column can decrease
    Find the minimum of row and column and decrease
    both by 2 till minimum become 0 or 1
    Now it will be the patter
    0 - 0 - L
    1 - 1 - R
    * - 0 - U
    * - 1 - D
*/
int main() {

    //Take number of test cases
    int t,n,m;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take n and m
        cin>>n>>m;

        //Find the minimum
        int mn = min(n,m);

        //Check which multiple of 2 it is
        mn = mn/2;

        //Decrease both by this multiple
        n -= mn*2;
        m -= mn*2;

        //Print according to the case
        if(n == 0)
            cout<<"L"<<endl;
        else if(m == 0)
            cout<<"U"<<endl;
        else if(n == 1)
            cout<<"R"<<endl;
        else
            cout<<"D"<<endl;
    }
}
