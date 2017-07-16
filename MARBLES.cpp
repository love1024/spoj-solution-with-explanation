#include<bits/stdc++.h>

using namespace std;

//To find the greatest common divisors of two numbers
long long gcd(long long a,long long b) {
    if(a == 0)
        return b;
    return gcd(b%a,a);
}

//Find the nCr of two numbers
long long nCr(long long n, long long r)
{
    //Initialize variables
	long long k = (r > n-r)? r : n-r;
	long long  m = n-k, den = 1, num = 1;

	//The method chosen here is that nCr can be represented as
	//n*(n-1)*(n-2)...(n-r+1) / r*(r-1)*r(r-2)...1
	for(long long i=k+1, j=m; i<=n && j>0; i++, j--)
	{
	    //Take next value of denominator and numerator
		den *= j;
		num *= i;

		//Find the gcd of two so as to cancel out both of them
		//to make them smaller so that further result can fit in long long int
		long long g = gcd(num, den);

		//Replace both with gcd
		num /= g;
		den /= g;
	}
	return num;
}

//The main idea behind the problem is Problem Stars and bars
//Suppose we have 7 stars
// * * * * * * *
//We want to place then 3 buckets so that each bucket get at least 1
//So we can place any stars starting from 1 in each bucket
//Consider putting stars like placing bars in between stars
// * * | * * | * * *
//So like this first and second bucket will contain 2 stars but third one
//will contain 3 stars
//We have n-1 spaces in between to put k-1 bars this can be done using
//n-1Ck-1
int main() {

    //Number of test cases
    int t;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take the n and k
        int n,k;
        cin>>n>>k;

        //Find the value of nCr
        cout<<nCr(n-1,k-1)<<endl;
    }
}
