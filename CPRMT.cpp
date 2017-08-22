#include<bits/stdc++.h>

using namespace std;

int main() {

    //Loop while there is input
    //And take two strings
    string a,b;
    while(getline(cin,a)) {
        if(a == "")
            break;
        getline(cin,b);

        //Sort both the strings as we have
        //to find lexographically smallest subsequence or
        //common letters
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        //Loop until one string goes out of length
        int i=0,j=0;
        while(i < a.length() && j < b.length()) {

            //If the current matches print the common character
            //and move on to next
            if(a[i] == b[j]) {
                cout<<a[i];
                i++,j++;
            }
            //Else if less than move the first character else move the second
            else if(a[i] < b[j])
                i++;
            else
                j++;
        }
        cout<<endl;
    }
}
