#include<bits/stdc++.h>

using namespace std;

int main() {
    int p;
    long double n,k,m,t;
    cin>>p;

    //while there is input
    while(p--) {

        //Take input
        cin>>n>>k>>m;
        t = 0;

        //While atoms are less
        while(n*k <= m) {
            n = n*k;
            t++;
        }

        //Print time
        cout<<t<<endl;
    }
}
