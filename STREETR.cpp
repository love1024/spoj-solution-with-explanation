#include<bits/stdc++.h>

using namespace std;

//Find greatest common divisor
int gcd(int a,int b) {
    if(a == 0)
        return b;
    return gcd(b%a,a);
}

int main() {

    //Find the number
    int n;
    cin>>n;

    // Take elements
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    // Sort elements
    sort(arr,arr+n);

    // Find difference of elements
    for(int i=1;i<n;i++)
        arr[i-1] = arr[i]-arr[i-1];

    //Find gcd of all
    int g = arr[0];
    for(int i=1;i<n-1;i++) {
        g = gcd(arr[i],g);
    }

    //Now find count of elements we need to insert
    int cnt = 0;
    for(int i=0;i<n-1;i++) {
        cnt += (arr[i]/g) - 1;
    }

    //Print answer
    cout<<cnt<<endl;
}
