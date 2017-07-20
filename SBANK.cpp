#include<bits/stdc++.h>

using namespace std;


int main() {

    //Number of test cases and bank accounts
    int t,n;
    cin>>t;

    //While there are test cases
    while(t--) {

        //Take number of accounts
        cin>>n;
        cin.ignore();

        //Take map which will store bank accounts as keys
        //And number of their occurrence as value
        map<string,int> mp;

        //Take bank account and put it in map
        string str;
        for(int i=0;i<n;i++) {
            getline(cin,str);

            //Increase the key value
            mp[str]++;
        }

        //Map will automatically sort  alphabetically
        //Print the account and their value
        map<string,int>::iterator it = mp.begin();
        for(;it != mp.end();it++) {
            cout<<(*it).first<<" "<<(*it).second<<endl;
        }

        //if it is not last test case print new line
        if(t != 0)
            cout<<endl;
    }
}
