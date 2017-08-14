#include<bits/stdc++.h>

using namespace std;

int main() {

    //Take the input
    int n,k=1;
    cin>>n;

    //Loop until there is input
    while(n != 0) {

        //Array to store input where 2 extras columns
        //are for input beyond the array limit and it will
        //store largest number so they cant be added into result
        //As we have to find minimum
        int arr[n][5];
        memset(arr,10000,sizeof(arr));

        //Take the input array
        for(int i=0;i<n;i++) {
            for(int j=1;j<=3;j++) {
                cin>>arr[i][j];
            }
        }

        //As we want the second column always in the last row
        //So we have to get rid of other tow
        //We make third column Largest as we cannot use it in input
        //To first column we add second column so that if there is
        //input through it, it will go to second column
        arr[n-1][3] = 10000;
        arr[n-1][1] += arr[n-1][2];

        //Loop over all rows
        for(int i=n-2;i>=0;i--) {

            //Loop over all three columns and find the minimum of
            //Right,Bottom,Bottom right,Bottom left nodes we have
            //already found
            for(int j=3;j>=1;j--) {
                arr[i][j] += min(min(min(arr[i][j+1],arr[i+1][j-1]),arr[i+1][j]),arr[i+1][j+1]);
            }
        }

        //Print the result
        cout<<k<<". "<<arr[0][2]<<endl;
        k++;
        cin>>n;
    }
}
