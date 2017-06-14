#include<bits/stdc++.h>

using namespace std;

int main() {

    //Take first number
    int n;
    cin>>n;

    //loop until number is not equal to zero
    while(n != 0) {

        //Take all numbers in vector
        vector<int> vec(n);
        for(int i=0;i<n;i++)
            cin>>vec[i];

        //loop over numbers
        int i;
        for(i=0;i<n;i++) {

            //if the position of current number is not equal to
            //number container at value container at position of
            //number at this position
            if(i+1 != vec[vec[i]-1])
                break;
        }

        //if loop completed then it is success
        if(i == n)
            cout<<"ambiguous"<<endl;
        else
            cout<<"not ambiguous"<<endl;

        cin>>n;
    }
    return 0;
}
