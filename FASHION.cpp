#include<bits/stdc++.h>

using namespace std;

int main() {

    //variable to store number of test cases
    int t;
    cin>>t;

    //variable to store number of input
    int n;

    //loop over all test cases
    while(t--) {

        //take number of persons
        cin>>n;

        //make array of n numbers
        int men[n];
        int women[n];

        //take input of hotness of men and women
        for(int i=0;i<n;i++)
            cin>>men[i];
        for(int i=0;i<n;i++)
            cin>>women[i];

        //sort the input of men and women
        //as we can find maximum hotness only
        //when we multiply maximum hotness among men
        //with maximum hotness among women
        sort(men,men+n);
        sort(women,women+n);

        //find sum of hotness by multiplying hotness
        //of each man and woman
        int sum = 0;
        for(int i=0;i<n;i++)
            sum += (men[i]*women[i]);

        //print the result
        cout<<sum<<endl;
    }
}
