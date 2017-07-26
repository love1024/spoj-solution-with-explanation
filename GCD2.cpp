#include<bits/stdc++.h>

using namespace std;

//Find greatest common divisor of two numbers
int gcd(int a,int b) {
    if(a == 0)
        return b;
    return gcd(b%a,a);
}

int main() {

    //Take the number of test cases,First number and second
    int n,A,B;

    //Second number as string
    char temp[300];
    scanf("%d",&n);

    //Loop over all test cases
    while(n--) {

        //Take first number as integer and second as string
        scanf("%d",&A);
        scanf("%s",temp);

        //If first number is zero simply print the second number
        if(A == 0) {
            printf("%s\n",temp);
            continue;
        }

        //Else convert second number into integer
        //By taking modulus with first number gcd will
        //be less than equal to smallest number
        B = 0;
        for(int i=0;temp[i] != '\0';i++)
            B = (B*10 + temp[i]-'0')%A;

        //Print the result
        printf("%d\n",gcd(A,B));
    }
    return 0;
}
