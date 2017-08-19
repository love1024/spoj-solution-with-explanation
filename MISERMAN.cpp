#include<bits/stdc++.h>

using namespace std;

int main() {

    //Take Cities and buses number
    int N,M;
    cin>>N>>M;

    //Make new array and make its left and rights extreme column as max
    int arr[N][M+2];
    for(int i=0;i<N;i++)
        arr[i][0] = arr[i][M+1] = 1000;

    //Take the array input
    for(int i=0;i<N;i++)
        for(int j=1;j<=M;j++)
            cin>>arr[i][j];

    //Start from second last column and check the minimum cost
    //With which we can reach at this position from next row
    for(int i=N-2;i>=0;i--) {
        for(int j=1;j<=M;j++) {
            arr[i][j] += min(min(arr[i+1][j-1],arr[i+1][j]),arr[i+1][j+1]);
        }
    }

    //Find the minimum from the first row it will be answer
    int res = INT_MAX;
    for(int i=1;i<=M;i++)
        res = min(res,arr[0][i]);
    cout<<res<<endl;
}
