#include<bits/stdc++.h>
using namespace std;



int main() {

    //Take input string
    string str;
    cin>>str;

    //While string is not equal to 0
    while(str != "0") {

        //Take three variables for storing result of
        //previous -1 , previous and current value
        //Like in fibonacci series
        long long a = 1,b=1,c=0;

        //store previous character
        int prev = str[0]-'0';

        //Traverse all string
        for(int i=1; i<str.length(); i++) {

            //Take current character
            int cur = str[i] - '0';

            //if it can combine with previous character
            //then we can use previous-1 result
            if((prev == 1) || (prev == 2 && cur <= 6))
                c += a;

            //If it can form a single input
            //then we can use previous result also
            if(cur != 0)
                c += b;

            //Make current equal to previous
            prev = str[i] - '0';

            //replace variable
            a = b;
            b = c;
            c = 0;
        }

        //print the result
        cout<<b<<endl;

        //Take next input
        cin>>str;
    }
    return 0;
}
