#include<bits/stdc++.h>

using namespace std;


int findGCD(int a,int b) {
    if(a == 0)
        return b;
    return findGCD(b%a,a);
}

int main() {
    int t,a,b,c;
    cin>>t;

    for(int i=1;i<=t;i++) {
        cin>>a>>b>>c;

        int lcm = findGCD( a, b);
        if(c%lcm == 0)
            cout<<"Case "<<i<<": "<<"Yes"<<endl;
        else
            cout<<"Case "<<i<<": "<<"No"<<endl;
    }
}
