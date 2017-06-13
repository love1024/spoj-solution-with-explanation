#include<bits/stdc++.h>

using namespace std;

int main() {

    //Number of test cases
    int t;
    cin>>t;

    //Loop over test cases
    while(t--) {

        //Number of fighters and maximum among both armies
        int n,m,maxG = -1,maxM = -1,x;
        cin>>n>>m;

        //Take godzilla army and find maximum among them
        for(int i=0;i<n;i++) {
            cin>>x;
            maxG = max(maxG,x);
        }

        //Take Mechagodzilla army and find maximum
        for(int i=0;i<m;i++) {
            cin>>x;
            maxM = max(maxM,x);
        }

        //If Godzilla army maximum strength fighter is equal or greater
        //Than Mecha army maximum fighter then Godzilla will win
        if(maxG >= maxM)
            cout<<"Godzilla"<<endl;
        else
            cout<<"MechaGodzilla"<<endl;
    }
    return 0;
}
