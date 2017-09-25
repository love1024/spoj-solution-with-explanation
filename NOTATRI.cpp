#include<bits/stdc++.h>

using namespace std;

int main() {

    //Take input number
    int n;
    scanf("%d",&n);

    //While there is input
    while(n != 0) {

        //Take numbers
        int arr[n];
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
        }

        //Sort numbers
        sort(arr,arr+n);

        //Try every possible sum and check how
        //many numbers are greater than this sum then
        //add that to result
        long long res = 0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {

                //Find upper bound on current sum
                if((upper_bound(arr,arr+n,arr[i]+arr[j]) - arr) < n) {
                    res += (n - (upper_bound(arr,arr+n,arr[i]+arr[j]) - arr));
                }
            }
        }

        //Print the result
        printf("%d\n",res);
        scanf("%d",&n);
    }
}
