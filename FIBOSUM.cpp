#include<bits/stdc++.h>

using namespace std;

//ref - https://www.hackerearth.com/practice/notes/matrix-exponentiation-1/
//ref - http://zobayer.blogspot.in/2010/11/matrix-exponentiation.html

//Number which represent MOD
const int MOD = 1000000007;

//Unit matrix
long long unit[2][2] = {{1,0},{0,1}};

//Base matrix which will be used for matrix exponentiation
long long base[2][2] = {{1,1},{1,0}};

//Function to multiply two matrices and put the result back in a
void  mul(long long a[2][2], long long b[2][2] ) {

    long long res[2][2];
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            res[i][j] = 0;
            for(int k=0;k<2;k++) {
                res[i][j] = (res[i][j] + (a[i][k]*b[k][j])%MOD)%MOD;
            }
        }
    }

    memcpy(a,res,sizeof(res));
}

//Multiply base matrix n times
//The concept here is to reuse the already
//fount matrices
//for example 64 = 8X8 = 4X2X4X2 = so we need to find 2 only
//Then we can find rest from it as every number can be represented with
//power of 2s. We can use binary notation for this for example for nth
//Number we use binary representation of n-1th number whenever the ith bit
//is set we add it into result else move forward
void matexp(long long arr[2][2],int n) {

    //Take temporary matrix and put base matrix in it
    long long temp[2][2];
    memcpy(temp,base,sizeof(base));


    //While there is number
    while(n > 0) {

        //If this bit is 1 multiply the result
        //matrix by current state of temporary matrix
        if(n%2 == 1)
           mul(arr,temp);

        //Move forward the current matrix by multiplying with itself
        mul(temp,temp);

        //Remove last bit to check the next one
        n /= 2;
    }

}


long long fiboSum(int n) {
    //if n is 0 return 0
    if(!n)
        return 0;

    //Take a matrix and put unit matrix in it
    //This matrix will represent the result
    long long arr[2][2];
    memcpy(arr,unit,sizeof(unit));

    //Find matrix exponentiation
    matexp(arr,n-1);

    return arr[0][0];
}

//The idea here is to use matrix exponentiation to find the
//nth fibonacci number if log time
//We use a matrix to represent all previous term on which the
//current term can depend then find the matrix which can give
//nth term in sequence by multiplying with itself n times.
int main() {

    //Take number of test cases and nth and mth fibonacci term
    int t,n,m;
    cin>>t;

    //Loop over all test cases
    //Here each nth term represent the sum of terms
    //from (0 to n-2) + 1
    //So we use it to find sum from n to m
    while(t--) {
        cin>>n>>m;

        //Find sum of all terms from 0 to n-1
        long long i = fiboSum(n+1);

        //Find sum of all terms from 0 to m
        long long j = fiboSum(m+2);

        //Find sum from n to m
        long long ans = j-i;

        //If answer became negative add MOD
        //As if while doing Mod first term becomes small
        if(ans < 0)
            ans += MOD;

        //Print the answer
        cout<<ans<<endl;
    }
}
