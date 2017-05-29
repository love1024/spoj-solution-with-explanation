#include<bits/stdc++.h>

using namespace std;

//creating alias for long long
//in case if number is large
typedef long long ll;

//function to reverse a given num
ll reverseNumber(ll num) {

    //declaring new variable to store result
    ll newNum = 0;

    //we take last digit of given num add it
    //to the result and divide the given num
    //by 10 so we check if remaining num is
    //greater than 0
    while(num > 0) {

        //Adding last digit of given number to result
        newNum = newNum*10 + (num%10);

        //dividing number by 10 to get rid of last digit
        num /= 10;
    }

    //returning reversed number
    return newNum;
}
int main() {

    //variable to store number of test cases
    ll t;
    cin>>t;

    //looping over all test cases
    while(t--) {

        //declaring some variables to store temp values
        ll a,b,c;

        //taking in input two given numbers
        cin>>a>>b;

        //reversing the given two numbers and adding them
        a = reverseNumber(a);
        b = reverseNumber(b);
        c = a+b;

        //reversing the added number and printing it.
        c = reverseNumber(c);
        cout<<c<<endl;
    }
}
