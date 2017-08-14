#include<bits/stdc++.h>

using namespace std;

int main() {

    //Take the input numbers
    int arr[10];
    for(int i=0;i<10;i++)
        cin>>arr[i];

    //Variables to store previous sum and current sum
    int prev=0,sum=0;

    //Loop over all variables
    for(int i=0;i<10;i++) {

        //Add current previous to current
        prev = sum;

        //Increase current sum
        sum += arr[i];

        //If sum is greater than 100
        //Then check which is minimum
        //Previous our current
        if(sum >= 100) {
            if(abs(100-prev) < abs(100-sum))
                cout<<prev<<endl;
            else
                cout<<sum<<endl;
            break;
        }
        //If it is last input and not greater
        //Than 100 then print it
        else if(i == 9)
            cout<<sum<<endl;
    }
}
