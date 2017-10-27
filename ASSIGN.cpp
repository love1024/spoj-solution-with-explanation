#include<bits/stdc++.h>

using namespace std;

//MAX subsets
#define MAX 1048576

//Array and temporary array
long long arr[MAX];
long long temp[MAX];

//To store power of 2
int dp[21];

//Store power of 2
void makeArray() {
    int cur = 1;
    for(int i=1;i<=20;i++, cur<<=1)
        dp[i-1] = cur;
}


int main() {

    //Find power of 2
    makeArray();

    //Take input
    int t,n;
    cin>>t;

    //While there is input
    while(t--) {

        //Take number
        cin>>n;

        //Store input
        vector< vector<int> > vec(n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                vec[i].resize(n);
                cin>>vec[i][j];
            }
        }

        //Initialize array to 0
        memset(arr,0,sizeof(arr));

        //Mark the position of ones in first row
        for(int i=0;i<n;i++) {
            if(vec[0][i] != 0)
                arr[dp[n-i-1]] = 1;
        }

        //Now go for each row and if there is 1 then
        //take this 1 as chosen and mark the choices for next row
        for(int i=0;i<n-1;i++) {

            //Initialize the temporary array to 0
            memset(temp,0,sizeof(temp));

            //Loop over all intermediate subsets found
            for(int j=0;j<MAX;j++) {

                //If it is found
                if(arr[j] != 0) {

                    //Loop over the next row
                    for(int k=0;k<n;k++) {

                        //If there is 1 in next row and this column is not set before
                        //in current input then put it into the array
                        if(vec[i+1][k] != 0 && (j&dp[n-k-1]) == 0) {
                            temp[j|dp[n-k-1]] += arr[j] ;
                        }
                    }
                }
            }

            //Make array as new array
            for(int i=0;i<MAX;i++)
                arr[i] = temp[i];
        }

        //Find max among all and print the result
        long long mx = 0;
        for(int i=0;i<MAX;i++)
            mx = max(mx,arr[i]);
        cout<<mx<<endl;
    }
}
