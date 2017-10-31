#include<bits/stdc++.h>

using namespace std;

//Check if n can divide string number
bool canDivide(string &str,int n) {

    int c = 0;
    for(int i=0;i<str.length();i++) {
        int cur = str[i] - '0';
        cur = c*10 + cur;
        c = cur%n;
    }
    return c==0?true:false;
}


int main() {

    //Take number of test cases
    int t,n;
    cin>>t;

    //While there is input
    while(t--) {

        //Take number
        cin>>n;

        //Take queue for breadth first search
        queue<string> que;

        //Insert starting number
        que.push("1");

        //While there is input
        while(true) {

            //Take out current value
            string cur = que.front();
            que.pop();

            //check if this can be divided by given number
            if(canDivide(cur,n)) {
                cout<<cur<<endl;
                break;
            }

            //Insert next binary values
            que.push(cur+"0");
            que.push(cur+"1");
        }
    }
}
