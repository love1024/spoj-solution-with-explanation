#include<bits/stdc++.h>

using namespace std;

int main() {

    //Total House and money
    int n,m;
    cin>>n>>m;

    //Take cost of houses
    long long arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    //mx will store max sum
    //j will be starting index of current consecutive houses
    //sum will be current sum of consecutive houses
    long long mx = 0,j=0;
    long long sum = 0;

    //Loop over all houses
    //Question will be find clusters of consecutive houses
    //Which can sum upto given money
    //We add a value to sum and if it will increase sum than money
    //Then we start decreasing form start
    for(int i=0;i<n;i++) {

        //Added price of current house to current sum
        sum += arr[i];

        //if sum is greater than the money available
        if(sum > m) {

            //check if adding current consecutive houses maximum we can
            //Is it maximum than previous maximum sum
            mx = max(mx,sum-arr[i]);

            //Now we have added a new value which has increased the total sum
            //We need to decrease it. So decrease value by leaving out houses
            //from start until we hit sum less than money so it will be our
            //next sum of consecutive houses
            while(sum > m && j <= i) {
                sum -= arr[j];
                j++;
            }

            //If we have found next consecutive sum then check if it is max
            if(j!=i)
                mx = max(mx,sum);
        }else
            //Else check if adding it to sum increase max
            mx = max(mx,sum);
    }

    //Print the max value
    cout<<mx<<endl;
}
