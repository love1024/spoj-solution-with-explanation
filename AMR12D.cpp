#include<bits/stdc++.h>

using namespace std;

//Function to check string is palindrome or not
bool check(string str) {
    int i=0,j=str.length()-1;

    while(i < j) {
        if(str[i] != str[j])
            return false;
        i++,j--;
    }

    return true;
}

//The main idea is to check if string is palindrome
//if yes then each substring will contain its reverse
//in it
int main() {

    //Take number of test cases
    int t;
    cin>>t;

    //Loop over all test cases
    string str;
    while(t--) {

       //Take the current string
       cin>>str;

        //If string is palindrome print YES else NO
        if(check(str))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
