#include<bits/stdc++.h>

using namespace std;

/*
    USE of Binary indexed tree
    to solve this problem.
    It can be easily solved using
    merge sort algorithm
*/
//Ref- find on geeeksforgeeks

//Find sum of numbers less than current
//number
long findSum(int arr[],int idx) {
    long sum = 0;
    while(idx > 0) {
        sum += arr[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}

//Update the number and numbers that can use it
void update(int bit[],int n,int idx,int val) {
    while(idx <= n) {
        bit[idx] += val;
        idx += (idx & (-idx));
    }
}

//Convert this array into relative array
//from lowest to highest. for example
//{8,4,3,5} will be {4,2,1,3}
void convert(int arr[],int n) {
    int temp[n];
    for(int i=0;i<n;i++)
        temp[i] = arr[i];
    sort(temp,temp+n);

    for(int i=0;i<n;i++) {
        arr[i] = lower_bound(temp,temp+n,arr[i]) - temp + 1;
    }
}

//Find number of inversions
long long findInvCount(int arr[],int n) {

    //Convert the array into size of n
    convert(arr,n);

    //Number of inversions
    long long invCnt = 0;

    //Take binary indexed tree array
    int bit[n+1];

    //Initialize it equal to zero
    memset(bit,0,sizeof bit);

    //Now find the inversion from right to left
    //As if some numbers are coming on left of
    //current number then they will give inversion
    for(int i= n-1 ; i>=0; i--) {

        //Find numbers that are already present
        //On left of this number that are greater
        //than this number
        invCnt += findSum(bit,arr[i]);

        //Add current number to binary index trees
        update(bit,n,arr[i],1);
    }

    //Return number of inversions
    return invCnt;
}



int main() {

    //Number of test cases
    int t;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take number of numbers
        int n;
        cin>>n;

        //Take numbers
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        //Find number of inversions
        cout<<findInvCount(arr,n)<<endl;

    }
}
