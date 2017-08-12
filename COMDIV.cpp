#include<bits/stdc++.h>

using namespace std;

//Function to find greatest common divisor of two numbers
int gcd(int a,int b){
    if(a == 0)
        return b;
    return gcd(b%a,a);
}

//Function to find number of divisors of a number
int numOfDiv(int num) {
    int cnt = 0;
    for(int i=1;i*i<=num;i++) {
        if(num%i == 0) {
            if(num/i == i)
                cnt++;
            else
                cnt += 2;
        }
    }
    return cnt;
}

//The idea here is to find number first GCD of a number
//it will be last number which can divide both numbers
//So find all divisors of GCD and this will give all common
//divisors of a two numbers
int main() {

    //Take number of test cases
    int t,a,b;
    scanf("%d",&t);

    //Loop over all test cases
    while(t--) {

        //Take two number
        scanf("%d%d",&a,&b);

        //Find GCD of two number as this will be last
        //Number which can divide both number
        int GCD = gcd(a,b);

        //Now find all divisors of GCD and this will give
        //Total number of common divisors of two numbers
        int cnt = numOfDiv(GCD);

        //Print the result
        printf("%d\n",cnt);
    }
}
