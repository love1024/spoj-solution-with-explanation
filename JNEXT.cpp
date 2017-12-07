#include<bits/stdc++.h>

using namespace std;

int main() {
    int t,n;
    cin>>t;

    //Loop over all test cases
    while(t--) {
        cin>>n;

        //Take number in array
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        arr[n] = 0;

        //Take temporary array to store count of each number
        int temp[10];
        memset(temp,0,sizeof(temp));

        //Now from last traverse all number
        //and check if we any number is greater
        //than its previous number, if yes then
        //we can create just next number
        int i;
        for(i=n-1;i>=0;i--) {
            temp[arr[i]]++;
            if(arr[i] < arr[i+1])
                break;
        }

        //If index is less than 0 we can't form a number
        if(i < 0) {
            cout<<-1<<endl;
        } else {

            //Print all number till the index
            for(int j=0;j<i;j++)
                cout<<arr[j];

            //Now find next greater number than current
            //number from where we will form new number
            for(int j=arr[i]+1;j<10;j++) {
                if(temp[j] != 0) {
                    cout<<j;
                    temp[j]--;
                    break;
                }
            }

            //Now print rest numbers in ascending order
            for(int j=0;j<10;j++){
                for(int k=0;k<temp[j];k++) {
                    cout<<j;
                }
            }
            cout<<endl;
        }
    }
}
