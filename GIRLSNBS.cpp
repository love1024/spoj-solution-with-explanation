#include<bits/stdc++.h>

using namespace std;

int main() {
    int g,b;
    cin>>g>>b;

    while(g != -1 && b != -1) {
        if(g == 0 && b == 0)
            cout<<0<<endl;
        else if(b == g || abs(b-g) == 1)
            cout<<1<<endl;
        else if(b > g){
            if(b%(g+1) == 0)
                cout<<(b/(g+1))<<endl;
            else
                cout<<(b/(g+1)+1)<<endl;
        } else {
            if(g%(b+1) == 0)
                cout<<(g/(b+1))<<endl;
            else
                cout<<(g/(b+1)+1)<<endl;
        }
        cin>>g>>b;
    }
    return 0;
}
