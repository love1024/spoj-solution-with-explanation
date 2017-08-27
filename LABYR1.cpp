#include<bits/stdc++.h>

using namespace std;

//Array to store input
char arr[1001][1001];

//Keep track of visited nodes
bool visited[1001][1001];

//Maximum distance between two points
int cnt = 0;

//position of max nodes find during first depth first search
int u,v;

//Depth first search
void dfs(int i,int j,int r,int c,int ct) {

    //If these node is not allowed return
    if(i < 0 || j < 0 || i >= r || j >= c)
        return ;
    else if(arr[i][j] == '#' || visited[i][j])
        return ;

    //Mark current node as visited
    visited[i][j] = true;

    //Call all neighbors
    dfs(i-1,j,r,c,ct+1);
    dfs(i,j-1,r,c,ct+1);
    dfs(i+1,j,r,c,ct+1);
    dfs(i,j+1,r,c,ct+1);

    //If distance of current node is more than best
    //Make it best and store position of current node
    if(ct > cnt) {
        cnt = ct;
        u = i;
        v = j;
    }
}

//Reset the boolean array
void reset() {
    for(int i=0;i<1001;i++)
        for(int j=0;j<1001;j++)
            visited[i][j] = false;
}

int main() {

    //Take number of test cases
    int t,r,c;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take columns and rows
        cin>>c>>r;

        //Take input graph
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                cin>>arr[i][j];
            }
        }

        //Reset the boolean array
        reset();
        cnt = 0;

        bool flag = false;

        //Find the first '.' position
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(arr[i][j] == '.') {

                    //Do dfs first to find position of farthest node
                    dfs(i,j,r,c,0);

                    //Reset the boolean array
                    reset();

                    //Call dfs with with position to find max distance between two nodes
                    dfs(u,v,r,c,0);
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }

        //Print the answer
        cout<<"Maximum rope length is "<<cnt<<"."<<endl;
    }

}
