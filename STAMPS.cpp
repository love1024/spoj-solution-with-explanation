#include<bits/stdc++.h>

using namespace std;

bool compare(int a,int b) {
    return a > b;
}

int main() {
    int t;
    cin>>t;

    for(int i=1;i<=t;i++) {
        int req,f;
        cin>>req>>f;

        vector<int> vec(f);
        long sum = 0;
        for(int j=0;j<vec.size();j++){
            cin>>vec[j];
            sum += vec[j];
        }
        if(sum < req){
            cout<<"Scenario #"<<i<<":\n"<<"impossible"<<endl;
            continue;
        }

        sort(vec.begin(),vec.end(),compare);

        sum = 0;
        for(int j=0;j<vec.size();j++) {
            sum += vec[j];
            if(sum >= req) {
                cout<<"Scenario #"<<i<<":\n"<<j+1<<endl;
                break;
            }
        }
    }
}
