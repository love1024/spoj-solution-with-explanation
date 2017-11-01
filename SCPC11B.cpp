#include<bits/stdc++.h>

using namespace std;

int main() {

    //Take number of stations
    int n;
    cin>>n;

    //While there is input
    while(n != 0) {

        //Take charging stations distance
        vector<int> vec(n);
        for(int i=0;i<n;i++)
            cin>>vec[i];

        //Sort stations
        sort(vec.begin(),vec.end());

        //Loop over all stations
        bool flag = true;
        for(int i=1;i<vec.size();i++) {

            //If it is last stations check if it can make a return
            if(i == vec.size() -1 && 1422 - vec[i] > 100) {
                flag = false;
                break;
            }else if(vec[i] - vec[i-1] > 200) {

                //Else check if distance is less than 200
                flag = false;
                break;
            }
        }
        if(flag)
            cout<<"POSSIBLE"<<endl;
        else
            cout<<"IMPOSSIBLE"<<endl;
        cin>>n;
    }
}
