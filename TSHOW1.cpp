#include<bits/stdc++.h>

using namespace std;

int main() {

    //Take number of test cases
    long long t,n;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take number
        cin>>n;

        //Find power of 2 which is greater than this number
        long long c = 1,num = 2,sum = 2;
        while(n > sum) {
            num <<= 1;
            sum += num;
            c++;
        }

        //Temp string
        string temp = "";

        //Find the position of start of this power of 2
        n = n - (sum - num) - 1;

        //Initialize number equal to 1
        num = 1;

        //Check the position of even or odd after subtracting by 2,4,8...
        //If even then number will be 5 else number will be 6
        for(int i=0;i<c;i++) {
            if(((n)/num)%2 == 0)
                temp += "5";
            else
                temp += "6";
            num <<= 1;
        }

        //Print the result
        for(int i=temp.length()-1;i>=0;i--)
            cout<<temp[i];
        cout<<endl;
    }
}
