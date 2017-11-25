#include<bits/stdc++.h>

using namespace std;

#define MAX 15


int main() {

    // pre compute array
    int arr[MAX][2];
    memset(arr,0,sizeof(arr));

    //If we can close at first two or we open first two
    arr[0][0] = 3;
    arr[0][1] = 2;

    //Go for of 3X2 tiles and store answer for closing
    //previous and opening previous ones
    for(int i=1;i<MAX;i++) {
        arr[i][0] = arr[i-1][0]*3 + arr[i-1][1];
        arr[i][1] = arr[i-1][0]*2 + arr[i-1][1];
    }

    //Print result according to the query
    int n=0;
    cin>>n;
    while(n != -1) {
        if(n&1)
            cout<<0<<endl;
        else if(n == 0)
            cout<<1<<endl;
        else
            cout<<arr[n/2-1][0]<<endl;
        cin>>n;
    }
}
