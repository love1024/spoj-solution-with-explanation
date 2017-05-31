#include<bits/stdc++.h>

using namespace std;

//ref- http://interactivepython.org/runestone/static/pythonds/BasicDS/InfixPrefixandPostfixExpressions.html

//NOTE THIS PROGRAM WILL ONLY WORK
//FOR FULLY PARANTHESIZE EXPRESSION
int main() {

    //constants to store the position of
    //left ,right and operator in expression
    //while removing from stack
    const int LEFT = 2;
    const int OPERATOR = 1;
    const int RIGHT = 0;

    //stack to store temporary data
    stack<string> stk;

    //variable to store test cases
    int t;
    cin>>t;

    //loop over all test cases
    while(t--) {

        //take expression into string
        string str;
        cin>>str;

        //loop over all characters of string
        for(int i=0;i<str.length();i++) {

            //take current character as string
            string cur = str.substr(i,1);

            //if current character is closing brace
            //it means we have expression to convert
            //into postfix expression
            if(cur == ")") {

                //temporary storage to hold expression
                //variables
                vector<string> temp;

                //remove the expression characters till
                //opening brace and remove the
                //character from stack
                while(stk.top() != "(") {
                    temp.push_back(stk.top());
                    stk.pop();
                }

                //remove the opening brace from stack
                stk.pop();

                //now convert the expression into postfix by putting
                //operator at last of expression
                stk.push(temp[LEFT]+temp[RIGHT]+temp[OPERATOR]);
            } else {

                //else push the current character into stack
                stk.push(cur);
            }
        }

        //print the expression and remove
        //it from stack
        cout<<stk.top()<<endl;
        stk.pop();
    }
}
