#include<bits/stdc++.h>

using namespace std;

//Substring patterns to search in sequence
string cases[] = {"TTT","TTH","THT","THH","HTT","HTH","HHT","HHH"};

//Array to hold the answer for each sub sequence
int ans[8];

int main() {

    //Number of test cases
    int t;
    cin>>t;

    //Loop over all test cases
    for(int j=1;j<=t;j++) {

        //Take current number and sequence
        int n,cnt;
        string seq;
        cin>>n>>seq;

        //Loop over all subsequence of coin
        for(int i=0;i<8;i++) {

            //Initialize count to 0
            cnt = 0;

            //Find position of current sub sequence int sequence
            size_t pos = seq.find(cases[i],0);

            //While there is another sub sequence loop over sequence
            while(pos != string::npos) {

                //Increment the count
                cnt++;

                //Find position of next subsequence in sequence but starting from 1 + position of
                //last found sequence
                pos = seq.find(cases[i],pos+1);
            }

            //store answer in sequence
            ans[i] = cnt;
        }

        //Print the result
        cout<<j<<" ";
        for(int i=0;i<8;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
