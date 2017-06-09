#include<bits/stdc++.h>

using namespace std;

int main() {

    //variable to store number
    string num;
    cin>>num;

    //loop while number is not zero
    while(num != "0") {

        //a and b will donate i-2 and i-1
        long long int a,b;
        a = b = 1;

        for(int i=1;i<num.length();i++) {

            //taking current and previous integer
            int cur = num[i]-'0';
            int prev = num[i-1]-'0';

            //if the current element is zero
            if(cur == 0) {

                //then if last is not 1 or 2 it is not valid input
                if(prev != 1 && prev != 2 ) {
                    b = 0;
                    break;
                } else {

                    //if last is 1 or 2 then cur and last will
                    //definitely form a combine letter(without last 0 is not valid)
                    //so current result  will be equal to letters formed till n-2
                    b = a;
                }
            } else {

                //if previous element was zero
                //it means it was combined with
                //n-2 so cant combined with current letter
                //so result will be equal to previous
                if(prev == 0)
                    b = a;
                else if(prev*10 + cur <= 26) {

                    //current can now form a single letter by itself
                    //and can also be added to previous letter
                    //so it will add both b and a to current result
                    int temp = b;
                    b = b + a;
                    a = temp;
                } else
                    //if current and previous not form valid letter
                    //then it will be single letter and result will be
                    //equal to previous result
                    a = b;
            }
        }

        //print result and get new number
        cout<<b<<endl;
        cin>>num;
    }
}
