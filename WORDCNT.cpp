#include<bits/stdc++.h>

using namespace std;

int main() {
    int t,cnt,mx,prev;
    string line,str;
    cin>>t;
    getline(cin,line);

    while(t--) {
        cnt = 0,mx = prev = 0;
        getline(cin,line);

        istringstream strm(line);

        while(strm>>str){
            if(str.length() == prev) {
                cnt++;
            } else {
                cnt = 1;
            }
            prev = str.length();
            mx = max(mx,cnt);
        }
        cout<<mx<<endl;
    }
}
