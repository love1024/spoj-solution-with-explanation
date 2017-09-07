#include<bits/stdc++.h>

using namespace std;

//Using relation between cubic roots and coefficients
//Three roots will be coordinates of 3d plane from 0,0,0 origin
//So just find need to find x1*x1 + x2*x2 + x3*x3
//where x1,x2,x3 are roots of cubic equation
int main() {

    //Take number of test cases
    int t;
    scanf("%d",&t);

    //Loop over all test cases
    while(t--) {

        //Take numbers
        long long a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);

        //print answer
        printf("%lld\n",(a*a - 2*b));
    }
}
