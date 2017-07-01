#include<bits/stdc++.h>

using namespace std;

//Get the sum of individual digit of number
int getSum(int n) {
    int sum = 0;
    while(n > 0) {
        sum = sum + (n%10)*(n%10);
        n /= 10;
    }
    return sum;
}

int main() {

    //Take number and count to count the number of steps
    int n,cnt = 1;
    cin>>n;

    //As the maximum number after adding all digits on
    //maximum number such as 9,99,999,999 cannot exceed 1000
    //So we have taken an array so keep track whether we have
    //already found that element before or not
    //Initialize it equal to false at start
    bool temp[1000];
    memset(temp,false,sizeof(temp));

    //Loop until some case
    while(true) {

        //Get sum of digits and make it equal to number
        n = getSum(n);

        //If current number is 1 then we can simply print the steps
        if(n == 1) {
            cout<<cnt<<endl;
            break;
        } else if(temp[n]) {

            //else if we have already visited that number before
            //it means this is a cycle and will repeat
            //so print -1 and exit
            cout<<-1<<endl;
            break;
        }

        //Else make current number visited and increment steps
        temp[n] = true;
        cnt++;
    }
}
