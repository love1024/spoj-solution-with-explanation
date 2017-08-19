#include<bits/stdc++.h>

using namespace std;

//Convert the string into required number
int convert(string &str) {
    int first = (str[0]-'0')*10 + (str[1]-'0');
    int second = (str[3]-'0');

    //Multiple first number of given number of zeros
    while(second > 0) {
        first *= 10;
        second--;
    }
    return first;
}

int main() {

    //Take the input strings
    string str;
    cin>>str;

    //While there is input
    while(str != "00e0") {

        //Convert the string in number
        int num = convert(str);

        //The Main point here is the pattern which
        //repeat after every power of 2. So after every power
        //of 2 we reach again at first position and after that
        //the next numbers will give answer in odd
        //For example for 10 . For 8 which is power of 2 answer is 1
        //for 9 answer will be 3 and for 10 answer will be 5
        int  p = 1;

        //Find the power of 2 less than this number
        while(true) {
            if(p<<1 > num)
                break;
            p <<= 1;
        }

        //Now now find the required odd number
        cout<<(2*(num-p) + 1)<<endl;

        //Take next input
        cin>>str;
    }
}
