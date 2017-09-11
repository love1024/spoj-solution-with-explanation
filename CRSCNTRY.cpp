#include<bits/stdc++.h>

using namespace std;

//Longest common subsequence problem

int main() {
    int t;
    cin>>t;

    while(t--) {
        vector<int> ages;
        int c,mx=0;

        cin>>c;
        while(c != 0) {
            ages.push_back(c);
            cin>>c;
        }

        cin>>c;
        while(c != 0) {
            vector<int> tom;
            do {
                tom.push_back(c);
                cin>>c;
            }while(c != 0);

            int arr[ages.size()+1][tom.size()+1];
            memset(arr,0,sizeof(arr));

            for(int i=0;i<ages.size();i++) {
                for(int j=0;j<tom.size();j++) {
                    if(ages[i] == tom[j])
                        arr[i+1][j+1] = 1 + arr[i][j];
                    else
                        arr[i+1][j+1] = max(arr[i+1][j],arr[i][j+1]);
                }
            }
            mx = max(mx,arr[ages.size()][tom.size()]);
            cin>>c;
        }

        cout<<mx<<endl;
    }
}
