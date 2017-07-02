#include<bits/stdc++.h>

using namespace std;

//Array to hold the answer for each sub sequence
int ans[8];

int main() {

    //Number of test cases
    int t;
    cin>>t;

    //Loop over all test cases
    for(int j=1;j<=t;j++) {

        //Take current number and sequence
        int n,cnt,p=0;
        string seq;
        cin>>n>>seq;

        memset(ans,0,sizeof ans);

        //Here the beauty of Logical operator lies
        //In the pattern 1 is used for H and 0 for T
        //So if we have 1 in our sequence of 3 for example
        //in 001 we want this 1 to move left to add next char
        //so we use (p << 1) to move it to next left place
        //Now if current character is also H then we also need to
        //Add 1 at this place so we use (seq[i] == 'H') and or it
        //with the sequence to add 1 if current character is H
        //Now we want only right most 3 digit in all the digits
        //contain in p so we & it with 7( 111 ) which will give
        //result with only ones at last 3 digits
        for(int i=0;i<seq.length();i++) {
            p = (p << 1) | (seq[i] == 'H');
            if(i > 1)
                ans[p&7]++;
        }

        //Print the result according to requirement
        cout<<j<<" ";
        for(int i=0;i<8;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
