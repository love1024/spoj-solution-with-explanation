#include<bits/stdc++.h>

using namespace std;

//Take greatest common divisor
int gcd(int a,int b) {
    if(a == 0)
        return b;
    return gcd(b%a,a);
}

int main() {

    //Take input
    long long w,h;
    cin>>w>>h;

    while(w != 0 && h!=0) {

        //If it is already square
        if(w == h) {
            cout<<1<<endl;
        } else {

            //Find gcd & LCM
            int GCD = gcd(w,h);
            long long LCM = (w*h)/GCD;

            //Now find number of tiles
            cout<<((LCM/w)*(LCM/h))<<endl;
        }
        cin>>w>>h;
    }
}
