#include<iostream>
#include<cstring>

using namespace std;

int main() {

    //Number of test cases
    int t;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Get height and width of tiles
        int h,w,res=0;
        cin>>h>>w;

        //Store the stones in 2d array
        int arr[h][w+2];
        memset(arr,0,sizeof arr);
        for(int i=0;i<h;i++)
            for(int j=1;j<=w;j++)
                cin>>arr[i][j];

        //Traverse array from 2nd row
        //and store in each tile the maximum we can
        //get by adding previous tiles into it
        for(int i=1;i<h;i++) {
            for(int j=1;j<=w;j++)
                arr[i][j] +=  max(max(arr[i-1][j-1],arr[i-1][j]),arr[i-1][j+1]);
        }

        //get the maximum number from last row
        for(int j=1;j<=w;j++)
            res = max(res,arr[h-1][j]);

        //Print the maximum
        cout<<res<<endl;
    }
    return 0;
}
