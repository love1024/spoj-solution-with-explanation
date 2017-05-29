#include<bits/stdc++.h>

using namespace std;

//Function to check whether number
//is prime or not
//return true if prime else false
bool isPrime(int n) {

    //if number is less than 2
    //then it is not prime
    // return false
    if(n < 2)
        return false;

    //Start from 2 check until sqrt of
    //given number. if any number can divide
    //given number then it is not
    //prime return false.
    for(int i=2;i*i<=n;i++) {
        if(n%i == 0)
            return false;
    }

    //if no number can divide given number
    //return true
    return true;
}

int main() {

    //variable to store number of test cases
    int t;
    cin>>t;

    //loop for all test cases
    while(t--) {

        //take start and end of range in
        //which prime numbers have to find.
        int m,n;
        cin>>m>>n;

        //traverse all these numbers and
        //check if number is prime. if yes
        //then print this number
        for(int i=m;i<=n;i++)
            if(isPrime(i))
                cout<<i<<endl;

        //put space between different test cases
        cout<<endl;
    }
    return 0;
}
