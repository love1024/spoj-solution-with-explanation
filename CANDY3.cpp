#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        long long  n;
        cin>>n;

        long long res = 0,x;
        for(int i=0;i<n;i++ ) {
            cin>>x;
            res += x;
            res = res%n;
        }

        if(res == 0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
