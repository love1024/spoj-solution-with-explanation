#include<bits/stdc++.h>

using namespace std;

//ref - http://zobayer.blogspot.in/2009/09/segmented-sieve.html
//http://lightoj.com/article_show.php?article=1001&language=english&type=pdf

//Max number upto which we need to find prime number
#define MAX 1000000

//It is basically square root of max to which we will traverse for loop
#define LMT 1000

//Number of primes up to MAX
#define MAXPR 78500

//Macro to find square of number
#define sq(x) ((x)*(x))

//Flag will store bits that donate prime or not prime
unsigned flag[MAX/64 + 1];

//It will store prime numbers
long long primes[MAXPR];

//READ ARTICLE FOR EXPLANATION OF THESE TWO
//Macro to get the bit. If 0 it is prime else if 1 not prime
#define getC(n) (flag[n>>6]&(1<<((n>>1)&31)))

//Macro to set the bit to make it 1 or not prime
#define setC(n) (flag[n>>6]|=(1<<((n>>1)&31)))


//Bitwise sieve to find sieve upto MAX
void sieve() {

    //Unsigned integers to donate range
    unsigned i,j,k;
    //Make first number as prime which is 2
    flag[0]|=0;

    //Start from 3 and take odd numbers
    for(i=3;i<LMT;i += 2) {

        //If number is prime
        if(!getC(i)) {

            //Then mark all its multiple as not prime
            for(j=i*i,k=i<<1;j<MAX;j += k)
                setC(j);
        }
    }

    //First prime is 2
    primes[0] = 2;

    //Find next prime and insert it into primes array
    for(i=3,j=1;i<MAX;i+=2) {
        if(!getC(i)) {
            primes[j] = i;
            j++;
        }
    }
}

//We here use modified fermat's theorem know as diophantus identity
//Which state that Any number can be represented as sum of squares
//If the prime factors of number of the form 4*k + 3 are in even pairs
//To understand this Consider following explanation
//Any number can be represented as = 4*k,4*k+1,4*k+2,4*k+3
//Now square of number can be represented as = 4*k,4*k+1
//If we add two squares they can be represented as = 4*k,4*k+1,4*k+2
//So if number is sum of two squares it must not be of form = 4*k+3
//or it must be in event pairs so that it can become = 2(4*k+3) = 4*k + 2
bool check(long long n) {

    //Take until the next prime number is less than given number
    for(int i=0;sq(primes[i]) <= n;i++) {

        //If this is prime factor of given number
        if(n%primes[i] == 0) {

            //Check how many times it occur
            int cnt = 0;
            while(n%primes[i] == 0) {
                n /= primes[i];
                cnt++;
            }
            //if this number is of form 4*k+3 and occur odd number of times
            //return false as it cannot be represented as sum of square of two numbers
            if((primes[i]-3)%4==0 && cnt&1)
                return false;
        }
    }
    //If the number left is of form 4*k+3
    //so return true as it is occurring 1 time time which
    //is odd
    if(n > 1 && (n-3)%4 == 0)
        return false;

    //Else return true
    return true;
}

int main() {

    //Number of test cases
    int t;
    long long n;
    cin>>t;

    //Use sieve to find prime numbers up to MAX
    sieve();

    //Loop over all test cases
    while(t--) {

        //Take the number
        cin>>n;

        //Check if can be represented using fermet theorem
        bool res = check(n);

        //Print result according to it
        if(res)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}
