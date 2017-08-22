#include<bits/stdc++.h>

using namespace std;

//Boolean to check node is visited or not
bool visited[60][60];

//For eight move around a node
int x[] = {-1,0,1};
int y[] = {-1,0,1};

//Pair in a 2d matrix having row,column and step to reach it
class Pair {
public:
    int r,c,step;
    Pair(int r,int c,int step) {
        this->r = r;
        this->c = c;
        this->step = step;
    }
};

int main() {

    //Take height and width
    int H,W,cnt = 1;
    cin>>H>>W;

    //Loop while there is input
    while(H != 0 && W != 0) {

        //Char array to store input
        //extra 2 for loop going out of scope
        //Initialize all
        char arr[H+2][W+2];
        memset(arr,'.',sizeof(arr));
        memset(visited,false,sizeof(visited));

        //Queue for breadth first search
        queue<Pair> que;

        //Take the matrix
        for(int i=1;i<=H;i++) {
            for(int j=1;j<=W;j++) {
                cin>>arr[i][j];

                //If the current character is A or start character push into queue
                if(arr[i][j] == 'A') {
                    que.push(Pair(i,j,1));
                    visited[i][j] = true;
                }
            }
        }

        //Cost of the last move
        int cst = 0;

        //While queue is not empty
        while(!que.empty()) {

            //Put of the current node from queue
            //and take its value
            Pair cur = que.front();
            que.pop();
            int i = cur.r, j = cur.c, stp = cur.step;
            cst = stp;

            //Check the 8 legal moves around if we can push and if not already pushed
            //and are 1 more than the current character
            for(int k=0;k<3;k++) {
                for(int l=0;l<3;l++) {
                    if(!visited[i+x[k]][j+y[l]] && arr[i+x[k]][j+y[l]] == arr[i][j]+1) {
                        que.push(Pair(i+x[k],j+y[l],stp+1));
                        visited[i+x[k]][j+y[l]] = true;
                    }
                }
            }
        }

        //Print the current result
        cout<<"Case "<<cnt<<": "<<cst<<endl;
        cnt++;
        cin>>H>>W;
    }
}
