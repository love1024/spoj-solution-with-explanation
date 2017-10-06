#include<bits/stdc++.h>

using namespace std;

#define MAX 1000005
int arr[MAX];
int pos[MAX];


int preCalculate() {
    for(int i=2;i<=100;i++){
        int cur = i*i*i;
        for(int j=cur;j<MAX;j += cur) {
            arr[j] = -1;
        }
    }
    int k = 1;
    for(int i=1;i<MAX;i++) {
        if(arr[i] != -1)
            pos[i] = k++;
    }
}

int main() {
    preCalculate();
    int t,n;
    cin>>t;

    for(int i=1;i<=t;i++) {
        cin>>n;
        int p;
        if(arr[n] != -1) {
           cout<<"Case "<<i<<": "<<pos[n]<<endl;
        } else {
           cout<<"Case "<<i<<": "<<"Not Cube Free"<<endl;
        }
    }
}
