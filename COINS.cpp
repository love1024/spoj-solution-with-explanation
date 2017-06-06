#include<bits/stdc++.h>

using namespace std;

//map to store already found results
//and use them for later
map<long long,long long> mp;

//recursive function which will find
//the maximum number we can get
long long findMax(int n) {

    //if this number is 0 then
    //return as can't go further
    if(n == 0)
        return 0;

    //if already contains result of
    //current number then return it
    if(mp.find(n) != mp.end()) {
        return mp[n];
    } else{

        //else find result of n/2,n/3,n/4
        //and choose max between the current one
        //or the sum of these three and store
        //it in map for later use
        return mp[n] = max((long long)n,findMax(n/2)+findMax(n/3)+findMax(n/4));
    }
}
int main() {

    //variable to store line and
    //number in that line
    string line;
    int num;

    //loop while there is a line
    while(getline(cin,line)) {

        //if there is no line break;
        if(line == "")
            break;

        //convert from string to number
        istringstream strm(line);
        strm>>num;

        //find maximum number recursively and print it.
        cout<<findMax(num)<<endl;
    }
}
