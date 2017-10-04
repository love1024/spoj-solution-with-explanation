#include<iostream>

using namespace std;

int main() {

    //Array to store calculated values
    int arr[1005];
    arr[1] = 5;

    //Each new pentagon will add
    //(current length + 1)*3 -2  + previous length
    //So we pre calculate these
    for(int i=2;i<=1000;i++) {
        arr[i] = ((i+1)*3 - 2) + arr[i-1];
    }

    //Take input and print the output
    int n;
    cin>>n;

    while(n != 0) {
        cout<<arr[n]<<endl;
        cin>>n;
    }
}
