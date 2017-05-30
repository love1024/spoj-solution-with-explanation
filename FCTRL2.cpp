#include<bits/stdc++.h>

using namespace std;

//Function to multiply number in the form
//of array with number a
//not here number in num is store in reversed
//order
void multiply(vector<int> &num,int a) {

    //variable to store carry while multiplication
    int carry = 0;

    //loop over all digit of number
    //and multiply a with each
    for(int i=0;i<num.size();i++) {

        //multiply with a and also add previous carry
        num[i] = num[i]*a + carry;

        //get current carry
        carry = num[i]/10;

        //only store last digit at this position
        num[i] = num[i]%10;
    }

    //loop until carry reduced to zero
    //push that carry to start of number
    //eg. if carry is 15 and number is 123 15
    //first we add 5 then 1 to current number
    //so number will become 15123
    while(carry) {
        num.push_back(carry%10);
        carry /= 10;
    }
}

//function to calculate factorial
//of given number n
void factorial(int n) {

    //vector to store individual digit
    //of factorial number
    vector<int> fact;

    //at start it will contain 1
    fact.push_back(1);

    //now from 2 multiply till
    //the end of number and store
    //the result in factorial vector
    for(int i=2;i<=n;i++)
        multiply(fact,i);

    //print the number as the number is reversed
    //so we start from last
    for(int i=fact.size()-1;i>=0;i--)
        cout<<fact[i];
    cout<<endl;
}
int main() {

   //variable to store test cases
    int t;
    cin>>t;

    //loop over all test cases
    while(t--) {

        //variable to hold current number
        int n;
        cin>>n;

        //find and print factorial of current number
        factorial(n);
    }
}
