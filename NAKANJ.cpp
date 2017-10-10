#include<bits/stdc++.h>

using namespace std;

//All moves of knight
int x[] = {-2,-1,1,2,-2,-1,1,2};
int y[] = {-1,-2,-2,-1,1,2,2,1};

//Node to store position of knight
class Node {
public:
    int x,y,d;
    Node(int x,int y,int d) {
        this->x = x;
        this->y = y;
        this->d = d;
    }
};


int main() {

    //Take number of test cases
    int t;
    cin>>t;

    //Loop over all test cases
    string a,b;
    while(t--) {

        //Take starting and ending point
        cin>>a>>b;

        //Get starting and ending position in integer
        int sx = a[0] - 'a';
        int sy = a[1] - '1';
        int ex = b[0] - 'a';
        int ey = b[1] - '1';

        //Take queue for breadth first search
        queue<Node> que;
        que.push(Node(sx,sy,0));

        //Do breadth first search to find minimum point
        while(!que.empty()) {
            Node cur = que.front();
            que.pop();
            int cx = cur.x;
            int cy = cur.y;
            if(cx == ex && cy == ey) {
                cout<<cur.d<<endl;
                break;
            }

            for(int i=0;i<8;i++) {
                if(cx+x[i] <= 7 && cx+x[i] >= 0 && cy+y[i] <= 7 && cy+y[i] >= 0)
                    que.push(Node(cx+x[i],cy+y[i],cur.d+1));
            }
        }
    }
}
