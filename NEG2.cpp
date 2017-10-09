#include<bits/stdc++.h>

using namespace std;

int main() {

    //Take the number
    long long n;
    cin>>n;

    //Take string as result
    string str = "";

    //While there is number
    while(n != 0) {

        //If we can divide this number exactly with base
        //Append zero and divide number
        if(n%-2 == 0) {
            str += "0";
            n = n/-2;
        } else {

            //Else append 1 and check for two cases
            str += "1";

            //If number is negative we need to go 1 multiple further
            //for example for -13 and -2 we need to go to -14 for positive
            //remainder as remainder cannot be negative
            if(n < 0)
                n = n/-2 + 1;
            else
                n = n/-2;
        }
    }

    //If number was 0 simple add 0
    if(str == "")
        str = "0";

    //Print the string in reverse order
    for(int i=str.length()-1;i>=0;i--)
        cout<<str[i];
}
