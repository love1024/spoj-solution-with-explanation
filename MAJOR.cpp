#include<bits/stdc++.h>

using namespace std;

// ref - http://www.geeksforgeeks.org/majority-element/

//Using moore voting algorithm
//The idea here is that cancel two different element
//and if there is majority element it will remain at end
//event after canceling all different element
//It can be or cannot be majority element so check if its
//count is greater than half
int isPossible(int arr[],int n) {

    //Let assume first element as major element
    //And initialize count to 1
    int major = 0,cnt=1;

    //Loop over all elements
    for(int i=1;i<n;i++) {

        //If it is equal to major element increase its count
        //Else cancel or decrease the current count
        if(arr[major] == arr[i])
            cnt++;
        else
            cnt--;

        //If count becomes zero choose current as new major element.
        //And initialize count again equal to zero
        if(cnt == 0) {
            major = i;
            cnt = 1;
        }
    }

    //Initialize count to 0
    cnt = 0;

    //Check if max element that we get is more than half
    for(int i=0;i<n;i++)
        if(arr[i] == arr[major])
            cnt++;

    //if it is more than half return element as MAX Element for failure
    if(cnt > n/2)
        return major;
    else
        return INT_MAX;
}

int main() {

    //Number of test cases
    int t;
    scanf("%d",&t);

    //Loop over all test cases
    while(t--) {

        //Number of elements
        int n;
        scanf("%d",&n);

        //Take elements
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        //Find if it is possible using moore voting algorithm and print result
        int res = isPossible(arr,n);
        if(res != INT_MAX)
            printf("YES %d\n",arr[res]);
        else
            printf("NO\n");
    }
}
