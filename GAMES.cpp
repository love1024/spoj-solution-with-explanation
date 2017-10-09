#include<bits/stdc++.h>

using namespace std;

//Find greatest common divisors of two numbers
int gcd(int a,int b) {
    if(a == 0)
        return b;
    return gcd(b%a,a);
}

int main() {

    //Take number of test cases
    int t;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take number as string
        string str;
        cin>>str;

        //Represent number in num/den form
        //as for 2.25 represent it as 225/100
        bool flag = false;
        int num=0,den=1;
        for(int i=0;i<str.length();i++) {
            if(flag)
                den = den*10 ;
            if(str[i] == '.') {
                flag = true;
                continue;
            }
            num = num*10 + (str[i]-'0');
        }

        //Now find gcd of num and den as it can divide both
        int GCD = gcd(num,den);

        //Divide den by gcd and print
        cout<<(den/GCD)<<endl;
    }
}
