#include<bits/stdc++.h>

using namespace std;

int main() {

    //Number of current test case
    int t = 1;

    //String of braces
    string str;
    cin>>str;

    //While there is input
    while(str[0] != '-') {

        //Take stack to get rid of completely closed braces
        stack<char> stk;

        for(int i=0;i<str.length();i++) {

            //if it is closing and last one was opening then it is complete
            //No need to add it
            if(str[i] == '}' && stk.size()>0 && stk.top() == '{')
                stk.pop();
            else
                //Else push it in stack
                stk.push(str[i]);
        }

        //Count to store operations required
        int cnt = 0;

        //While there is input in stack
        while(!stk.empty()) {

            //Take top two stacks from stack
            char a,b;
            a = stk.top();
            stk.pop();
            b = stk.top();
            stk.pop();

            //If they are opposite then we need two operations
            if(a == '{' && b == '}')
                cnt += 2;
            else

                //Else one operation is required
                cnt++;
        }

        //Print the output
        cout<<t<<". "<<cnt<<endl;

        //Take next string
        cin>>str;
        t++;
    }
}
