#include<bits/stdc++.h>

using namespace std;

#define MOD 10000007

//Modular exponentiation
long long expMod(long long a,long long b) {
    if(a == 1 || b == 0)
        return 1;
    else if(b == 1)
        return a;
    long long res = expMod(a,b/2);

    if(b&1)
        return (((res*res)%MOD)*a)%MOD;
    else
        return (res*res)%MOD;
}

int main() {

    //Take input
    long long n,k;
    cin>>n>>k;

    //While there is input
    //Following terms are calculated as rest all will get canceled with each other.
    while(n != 0 && k != 0) {
        long long res = (expMod(n,n) + expMod(n,k) + 2*expMod(n-1,n-1) + 2*expMod(n-1,k))%MOD;
        cout<<res<<endl;

        cin>>n>>k;
    }
}
