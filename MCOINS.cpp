#include<bits/stdc++.h>

using namespace std;

//Array to store previous values
bool arr[1000005];

int main() {
    int K,L,m,n;

    //Take variables
    cin>>K>>L>>m;

    //We will find the winning or losing state
    //If somehow after given steps we can reach
    //The Losing state then we can will as it will losing
    //State of other.
    for(int i=1;i<=1000000;i++) {

        //Let current state be losing state
        bool state = false;

        //If we can find any losing state then we can win
        //Make it true state
        if(!arr[i-1])
            state = true;
        if(i >= K && !arr[i-K])
            state = true;
        if(i >= L && !arr[i-L])
            state = true;

        //Store current  state
        arr[i] = state;
    }

    //Print the result according to winning state
    for(int i=0;i<m;i++) {
        cin>>n;

        if(arr[n])
            cout<<"A";
        else
            cout<<"B";
    }
}
