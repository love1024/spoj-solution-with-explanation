#include<bits/stdc++.h>

using namespace std;

//Function to find the maximum of minimum distance between two cows
long long findDist(vector<long long> &vec,int c) {

    //number of stalls
    long long n  = vec.size();

    //Minimum distance between two cows can be 1
    long long lo = 1;

    //Maximum distance last - first
    //Here we used double of last so that we can
    //get maximum distance in binary search
    long long hi = vec[n-1]*2;

    //Loop while lower is less than higher
    while(lo < hi) {

        //Find the mid of both distances
        long long x = lo + (hi-lo+1)/2;

        //Number of we can place and current distance
        long long co  =1,cur = 0;

        //Loop over all stalls
        for(int i=1;i<n;i++) {

            //if the current distance and previous distance between
            //Stalls are greater than the distance required between
            //Cows then we can place a cow here
            if((vec[i]-vec[i-1]) + cur >= x) {
                co++;

                //Reinitialize the current distance
                cur = 0;
            } else {

                //Else if we cannot place a cow here add it to current
                //distance we have covered while searching for stall
                //whose distance must be greater than x
                cur += (vec[i]-vec[i-1]);
            }
        }

        //if for distance x
        //We can place less cows than required
        //Then we need to decrease the distance
        //As to place more cows
        if(co < c)
            hi = x-1;
        else
        //We can place required cows in this distance
        //But we want to maximize the distance so
        //try to increase the limit without losing current
        //x as it can be answer so lower is equal to x
        //not x + 1
            lo = x;
    }

    //return the answer
    return lo;
}

int main() {

    //Number of test cases
    int t;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Total number of stalls and cows
        int n,c;
        cin>>n>>c;

        //Take position of all stalls
        vector<long long> vec(n);
        for(int i=0;i<n;i++)
            cin>>vec[i];

        //Sort the input for binary search
        sort(vec.begin(),vec.end());

        //Find maximum of minimum distance between two cows
        cout<<findDist(vec,c)<<endl;
    }
}
