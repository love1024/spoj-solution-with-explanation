#include<bits/stdc++.h>

using namespace std;

// The equation can be written as
// a*b + c = d*(e+f)
//We will find all possible combination
//of right hand side then use them in left hand side
int main() {

    //Number of input numbers
    int n;
    scanf("%d",&n);

    //Vector to store right hand side results
    vector<int> vec;

    //Take input numbers
    int arr[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }

    //Find all combinations of right hand side
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            for(int k=0;k<n;k++) {
                if(arr[i] != 0)
                    vec.push_back((arr[j]+arr[k])*arr[i]);
            }
        }
    }

    //Sort the combinations
    sort(vec.begin(),vec.end());

    //Count number of cases
    long long cnt = 0;

    //Try all cases of left hand side
    for(int a=0;a<n;a++) {
        for(int b=0;b<n;b++) {
            for(int c = 0;c<n;c++) {

                //if the right hand side is equal to left hand side
                if(lower_bound(vec.begin(),vec.end(),arr[a]*arr[b]+arr[c]) != vec.end()) {

                    //Find how many left hand values are there for this value and add to count
                    int low = lower_bound(vec.begin(),vec.end(),arr[a]*arr[b]+arr[c]) - vec.begin();
                    int high = upper_bound(vec.begin(),vec.end(),arr[a]*arr[b]+arr[c]) - vec.begin();
                    cnt += (high-low);
                }
            }
        }
    }

    //Print the result
    printf("%d",cnt);

}
