#include<bits/stdc++.h>

using namespace std;

int main() {

    //variable to store number of elements
    int n;

    //loop till break
    while(true) {

        //take input
        cin>>n;

        //if input is -1 break
        if(n == -1)
            break;

        //array to store number and
        //sum to store sum of all numbers
        int arr[n];
        int sum = 0;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            sum += arr[i];
        }

        //now find average of their as
        //as this will be the number at
        //which everyone has equal candies
        int avg;
        if(sum%n == 0)
            avg = sum/n;
        else {

            //if average is not an integer
            //it everyone cannot get equal
            //candies so print -1
            cout<<-1<<endl;
            continue;
        }

        //count to store number of candies
        //which we are going to move
        //to make everyone has equal candies
        int cnt = 0;
        for(int i=0; i<n; i++) {

            //if current bag more candies
            //then move this to average and store
            //the moved candies into counts
            if(arr[i] > avg)
                cnt += (arr[i]-avg);
        }

        //print the moved candies
        cout<<cnt<<endl;
    }
}
