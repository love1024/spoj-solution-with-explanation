#include<bits/stdc++.h>

using namespace std;

//There is also a O(1) solutions
//which require some calculation to find the
//perfect square
int main() {

    //Take the number
    int n;
    cin>>n;

    //Loop until number is not equal to -1
    while(n != -1) {

        //if the number is 1 simply print Y
        if(n == 1)
            cout<<"Y"<<endl;
        else {

            //else find increase the series from 1 until
            //we reach equal to given number or greater than that
            //series is 1 + 6 + 12 + 18 + 24 ....
            //if at last we reach equal to n it means
            //it is a beehive number else not
            long long i = 1,sum = 1;
            while(sum < n) {
                sum = sum + 6*i;
                i++;
            }

            //If sum is equal to given number then print Y else N
            if(sum == n)
                cout<<"Y"<<endl;
            else
                cout<<"N"<<endl;
        }

        //Take next number
        cin>>n;
    }
    return 0;
}
