#include<bits/stdc++.h>

using namespace std;

//To store for each number the number of prime factors
int primes[4000];

//Flag to check whether number is prime or not
bool flag[4000];

//Sieve
void sieve(int n) {

    //Initialize flag array to true
    memset(flag,true,sizeof(flag));

    //Loop over all numbers
    for(int i=2;i<=n;i++) {

        //If current number is prime
        if(flag[i]) {

            //mark all its multiple not prime
            for(int j=i+i;j<=n;j += i) {
                flag[j] = false;

                //Increase the current number prime factors
                primes[j]++;
            }
        }
    }
}

int main() {

    //Call sieve
    sieve(4000);

    //Store the number those with more than 3 prime factors
    vector<int> num;
    for(int i=0;i<4000;i++)
        if(primes[i] > 2)
            num.push_back(i);

    //Take number of test cases
    int t,n;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take the number
        cin>>n;

        //Print the nth lucky number
        cout<<num[n-1]<<endl;
    }
}
