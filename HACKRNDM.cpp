#include<bits/stdc++.h>

using namespace std;

int main() {
    //Taking number and difference
    int n,k;
    cin>>n>>k;

    //Taking the array
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    //Sorting for binary search
    sort(arr,arr+n);

    //Loop over all numbers
    int cnt = 0;
    for(int i=0;i<n;i++) {

        //Add k to current number and check whether this sum exist
        //if yes then the difference exist increase count
        //Use binary search for finding number
        int cur = arr[i]+k;
        if(binary_search(arr,arr+n,cur))
            cnt++;
    }
    cout<<cnt<<endl;
}
