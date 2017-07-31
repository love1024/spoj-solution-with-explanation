#include<bits/stdc++.h>

using namespace std;

int main() {

    //Number of test cases,first and second number
    int t,n,m;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take first number all test heights
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];

        //Take second number and all its heights
        cin>>m;
        vector<int> b(m);
        for(int i=0;i<m;i++)
            cin>>b[i];

        //Sort first and second
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        //Take two pointers to find the minimum difference
        //As we want to reach as close as possible so whenever
        //a number is small than other we increase its value to make
        //it close to the other one. we go until one of the list is empty
        //so above it difference will only increase
        int i = 0,j = 0,mn = INT_MAX;
        while(i < n && j < m) {

            //Check if this difference is minimum
            mn = min(mn,abs(a[i]-b[j]));

            //If first number is small increase it else second
            if(a[i] < b[j])
                i++;
            else
                j++;
        }

        //Print the result
        cout<<mn<<endl;
    }
}
