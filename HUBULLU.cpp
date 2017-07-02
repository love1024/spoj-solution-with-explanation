#include<bits/stdc++.h>

using namespace std;

//The intuition behind this problem is
//That player can be at losing state or winning state
//at start. If he is at losing state then he can simple
//choose 1 at start as it will not effect the list and can
//Pass his losing state to second player.so he will win
//So no matter what number is whatever player will play first
//will always win.
int main() {

    //Number of test cases
    int t;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take number and who will start first
        int n,s;
        cin>>n>>s;

        //print answer according to who is playing first
        if(s == 0) {
            cout<<"Airborne wins."<<endl;
        } else {
            cout<<"Pagfloyd wins."<<endl;
        }
    }
    return 0;
}
