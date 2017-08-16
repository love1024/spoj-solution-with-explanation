#include<bits/stdc++.h>

using namespace std;

//The idea here is
//Any number can be represented in power of 2
//And we can make any number from these combinations
//For example we can make 7 as 1 + 2 + 4
//So only 2 cuts are required at 2 and 4
int main() {

    //Take number n
    int n;
    cin>>n;

    //While There is input
    while(n != 0) {

        //If it is 1 just print 0
        if(n == 1)
            cout<<0<<endl;
        else {

            //Else Find lowest power of 2
            int cur = 1;
            int cnt = 0;
            while(cur < n) {
                cur <<= 1;
                cnt++;
            }

            //Print the result
            cout<<cnt-1<<endl;
        }

        //Take next input
        cin>>n;
    }
}
