#include<bits/stdc++.h>

using namespace std;

//xor operator between equal number
//result in 0 so here we will use xor
//operator between all numbers
//which will make double numbers 0 and we
//left with unique number
int main() {

    //Take the input
    int n,x,u=0;
    cin>>n;

    //Scan all numbers and xor with the previous result
    for(int i=0;i<n;i++) {
        scanf("%d",&x);
        u = u^x;
    }

    //Print the result
    printf("%d",u);
    return 0;
}
