#include<bits/stdc++.h>

using namespace std;

//Set to store found results
set< pair<int,int> > st;

//Node for queue with x,y coordinates and m moves

class Node {
public:
    int x,y,m;
    Node(int x,int y,int m) {
        this->x = x;
        this->y = y;
        this->m = m;
    }
};

//Find gcd of two numbers
int gcd(int a,int b) {
    if(a == 0)
        return b;
    return gcd(b%a,a);
}


int main() {

    //Take number of test cases
    int t,a,b,c;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take numbers
        cin>>a>>b>>c;

        //Find GCD of numbers
        int GCD = gcd(a,b);

        //If given number is not multiple of GCD or is greater
        //then given numbers then print -1
        if(c%GCD !=0 ||(c > a && c > b)) {
            cout<<"-1"<<endl;
            continue;
        }

        //Declare queue and insert starting point
        queue<Node> que;
        que.push(Node(0,0,0));

        //At each step we can move to 6 nodes
        //First is fill completely
        //Second is fill completely
        //Pour water from first to second
        //Pour water from second to first
        //Empty first
        //Empty second
        //We use map to already found results
        while(!que.empty()) {
            Node cur = que.front();
            que.pop();
            int x = cur.x, y = cur.y , m = cur.m;

            //If this is the required number
            //print answer and break
            if(x == c || y == c) {
                cout<<m<<endl;
                break;
            }

            //Else perform all 6 cases if not already found
            if(st.find(pair<int,int>(a,y)) == st.end()) {
                que.push(Node(a,y,m+1));
                st.insert(pair<int,int>(a,y));
            }
            if(st.find(pair<int,int>(x,b)) == st.end()) {
                que.push(Node(x,b,m+1));
                st.insert(pair<int,int>(x,b));
            }
            if(st.find(pair<int,int>(x-min(x, b-y),y+min(x, b-y))) == st.end()) {
                que.push(Node(x-min(x, b-y), y+min(x, b-y),m+1));
                st.insert(pair<int,int>(x-min(x, b-y),y+min(x, b-y)));
            }
            if(st.find(pair<int,int>(x+min(y, a-x),y-min(y, a-x))) == st.end()) {
                que.push(Node(x+min(y, a-x), y-min(y, a-x),m+1));
                st.insert(pair<int,int>(x+min(y, a-x),y-min(y, a-x)));
            }
            if(st.find(pair<int,int>(0,y)) == st.end()) {
                que.push(Node(0,y,m+1));
                st.insert(pair<int,int>(0,y));
            }
            if(st.find(pair<int,int>(x,0)) == st.end()) {
                que.push(Node(x,0,m+1));
                st.insert(pair<int,int>(x,0));
            }
        }

        //Clear the set
        st.clear();
    }
}
