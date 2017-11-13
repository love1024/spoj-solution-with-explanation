#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

//Find multiplication of two large number with mod
ULL mul(ULL a,ULL b,ULL mod) {
    if(b == 1)
        return a;
    ULL res = mul(a,b/2,mod);
    res = (2*res)%mod;
    if(b&1)
        res = (res + a)%mod;
    return res;
}

//Find power of two large number with mod
ULL power(ULL a,ULL p,ULL mod) {
    if(p == 1)
        return a;
    ULL res = power(a,p/2,mod);
    res = mul(res,res,mod);
    if(p&1)
        res = mul(res,a,mod);
    return res;
}

//Miller Rabin randomized primality test
bool millerRabin(ULL a,ULL n) {

    //Find n-1 = 2^k*u
    ULL k = 0,u=n-1;
    while(u%2 == 0) {
        u /= 2;
        k++;
    }

    //Find a^u
    ULL prev = power(a,u,n),cur;

    //Now multiple with this power of 2 at each step
    //Check if we can find any non trivial square root of 1
    //Which basically say that find any number x whose square
    //will give x*x(mod n) == 1 but x itself not 1
    //So it will not be a prime
    for(int i=0;i<k;i++) {
        cur = mul(prev,prev,n);
        if(cur == 1 && prev != 1 && prev != n-1)
            return true;
        prev = cur;
    }

    //If it still follows fermat's theorm
    if(cur != 1)
        return true;

    //It is prime
    return false;
}


int main() {
    int t;
    cin>>t;

    ULL n ,i;
    while(t--) {
        cin>>n;
        bool isPrime = true;

        if(n < 2)
            isPrime = false;
        else if(n >3) {

            //Test for random number
            for(int i=0;i<20;i++) {

                //Take random number between 2 and n-1
                ULL a = 2 + rand()%(n-2);

                //Apply miller Rabin
                if(millerRabin(a,n)) {
                    isPrime = false;
                    break;
                }
            }
        }

        //Print answer
        if(isPrime)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
