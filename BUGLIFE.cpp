#include<bits/stdc++.h>

using namespace std;

//Function to check whether we can color the graph using two color 0 and 1
bool color(bool visited[],int col[],vector< vector<int> > &graph,int c,int parent,int u) {

    //Make the current node as visited
    visited[u] = true;

    //Add color to current node
    col[u] = c;

    //Visit all neighbor of current node
    for(int i=0;i<graph[u].size();i++) {

        //If the neighbor is already visited and is not parent of
        //current node then it is cycle
        if(visited[graph[u][i]] && graph[u][i] != parent){

            //if color of the cycle point is same as current node
            //then return false as we cannot color the graph
            if(col[graph[u][i]] == c)
                return false;

        // Else if it is not parent
        } else if(graph[u][i] != parent){

            //make the next call to neighbor and change to color
            //if return value if false return false
            if(!color(visited,col,graph,c==0?1:0,u,graph[u][i]))
                return false;
        }
    }

    //Return true if all condition met
    return true;
}

int main() {

    //Take number of test cases, number of nodes and edges.
    int t, n, e;
    cin>>t;

    //Loop over all test cases
    for(int i=1;i<=t;i++) {

        //Take number of nodes and edges
        cin>>n>>e;

        //Take graph , visited to check node is visited once
        //Color array of each node color
        vector< vector<int> > graph(n+1);
        bool visited[n+1];
        int col[n+1];

        //Initialized visited to false,Color array to -1
        memset(visited,false,sizeof(visited));
        memset(col,-1,sizeof(col));

        //Construct a graph from edges
        int u,v;
        for(int i=0;i<e;i++) {
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        //Flag to see if we can color a graph
        bool flag = true;

        //Loop over all nodes
        for(int i=1;i<=n;i++) {

            //If the node is not visited
            if(!visited[i]) {

                //if the return value of coloring is false
                //means we cannot color the graph the break;
                if(!color(visited,col,graph,0,i,i)) {
                    flag = false;
                    break;
                }
            }
        }

        //Print the result according to flag
        cout<<"Scenario #"<<i<<":"<<endl;
        if(flag) {
            cout<<"No suspicious bugs found!"<<endl;
        } else {
            cout<<"Suspicious bugs found!"<<endl;
        }

    }
}
