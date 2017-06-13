#include<bits/stdc++.h>

using namespace std;

//ref- Read about triangular number
//NOTICE- you can also solve or find diagonal using a loop
//It will work or you will not get TLE

//Find on which diagonal of triangular series
//current element lies
int findDiagonal(int n) {
    return (ceil((sqrt(8*n+1)-1)/2));
}


int main() {

    //Take total number of cases
    int t;
    cin>>t;

    //Loop over all cases
    while(t--) {

        //Take the term to search
        int term;
        cin>>term;

        //Find diagonal on which this element lies
        int d = findDiagonal(term);

        //Find the difference of element from end of this row
        //or how many to subtract from last of this row
        int diff = d*(d+1)/2 - term;

        //print answer according to even or odd row
        //after finding the element to find on this row
        if(d%2 != 0) {
            cout<<"TERM "<<term<<" IS "<<(1+diff)<<"/"<<(d-diff)<<endl;
        } else {
            cout<<"TERM "<<term<<" IS "<<(d-diff)<<"/"<<(1+diff)<<endl;
        }
    }
}
