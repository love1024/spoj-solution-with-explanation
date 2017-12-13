#include<bits/stdc++.h>

using namespace std;

int main() {

    //Take input and print answer
    long long n,m;
    scanf("%lld%lld",&n,&m);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    sort(arr,arr+n);
    long long i = arr[0],j = arr[n-1],mid,cur;

    //Just c++ upper bound
    while(i < j) {
        mid = i + (j-i+1)/2,cur = 0;
        for(int k=0;k<n;k++) {
            if(arr[k] > mid)
                cur += (arr[k]-mid);
        }
        if(cur < m)
            j = mid-1;
        else
            i = mid;
    }

    //Print the answer
    printf("%lld",i);
}
