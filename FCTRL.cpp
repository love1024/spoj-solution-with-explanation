#include<bits/stdc++.h>

using namespace std;

//ref - http://www.mytechinterviews.com/how-many-trailing-zeros-in-100-factorial

//function to compute occurrences of
//number b till number a
//for a = 25 and b = 5
//b occurs at 5,10,15,20,25.
//so when 25 divided by 5 it gives 5
//but 25 contains 5 two times so
//when divided by 25 after doubling b
//1 will get added to result and
//result will be 6
int countOccurences(int a,int  b) {

    //variable to store result
    int res = 0;

    //variable to store original value of b
    int orig = b;

    //loop while b is less than a
    while(a/b > 0) {

        //divide a by b and add integer part to result
        res += (a/b);

        //double the b
        b *= orig;
    }

    //return the result
    return res;
}
int main() {

    //variable to store number of test cases
    int t;
    cin>>t;

    //loop over all test cases
    while(t--) {

        //variable to store the number
        int n;
        cin>>n;

        //get occurrences of number 5 and 2 in given number
        //as these two numbers will form 0 in result
        //and the minimum of these two will be our result.
        int minimum = min(countOccurences(n,5),countOccurences(n,2));
        cout<<minimum<<endl;
    }
}
