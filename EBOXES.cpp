#include<bits/stdc++.h>

using namespace std;

//ref - http://codegeeeks.blogspot.in/2014/10/spoj-problem-4343-empty-boxes-eboxes.html
//For explanation

int main() {

    int t,N,K,T,F;
    cin>>t;

    while(t--) {
        cin>>N>>K>>T>>F;

        F = F + (F-N)/(K-1);

        cout<<F<<endl;
    }
}
