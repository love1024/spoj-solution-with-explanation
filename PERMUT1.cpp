#include<bits/stdc++.h>

using namespace std;


int inv[100];


//Function to find Inversion of given e digits starting from l
//The main idea is that we can make inversion using base cases
//For 24(4 digits) we can make is using 4 times 6(3 digits)
//6 we can make using 3 times 2(2 digits)
void findInv(int l,int e) {

    //Return if all inversions are found
    if(l > e)
        return;

    //Temporary storage
    int temp[100];
    memset(temp,0,sizeof(temp));

    //Add the current inversion array l times
    //And at each step starting from one step ahead
    //For example
    //1 1 0 0
    //0 1 1 0
    //0 0 1 1
    for(int i=0;i<l;i++) {
        for(int k=i;k<100;k++) {
            temp[k] += inv[k-i];
        }
    }

    //Making inversion array equal to temporary
    for(int i=0;i<100;i++)
        inv[i] = temp[i];

    //Now find 1 + current digits
    findInv(l+1,e);
}

int main() {
    int t;
    cin>>t;


    //Loop over all test cases
    while(t--) {
        int n,k;
        cin>>n>>k;

        //If there is only one digit
        if(n == 1) {
            cout<<(k==0?1:0)<<endl;
            continue;
        }

        //Initialize the inversion array
        memset(inv,0,sizeof(inv));

        //For less than 3 digit number result is obvious
        inv[0] = inv[1] = 1;

        //Calculate result starting from 3
        findInv(3,n);

        cout<<inv[k]<<endl;
    }
}
