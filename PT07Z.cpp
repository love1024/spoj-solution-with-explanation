#include<bits/stdc++.h>

using namespace std;

//Variable to store
//MaxNode we can reach in our first pass of DFS
//maxLen is the maximum length of path when started
//from maxNode
int maxNode = 0,maxLen = 0;

//Depth first search function
int dfs(vector< vector<int> > &vec,bool visited[],int u,int len) {

    //Make current node as visited
    visited[u] = true;

    //Call all neighbors if they are not visited with length 1
    //more than the current one
    for(int i=0;i<vec[u].size();i++) {
        if(!visited[vec[u][i]])
            dfs(vec,visited,vec[u][i],1+len);
    }

    //if length of current node from start of dfs is more than
    //previous maxLen then make this maxNode
    if(len > maxLen)
        maxNode = u;

    //Store the max length in maxLen variable
    maxLen = max(maxLen,len);
}

int main() {

    //Store number of nodes
    int n,u,v;
    cin>>n;

    //Store the edges in adjacency list
    vector< vector<int> > vec(n+1);
    for(int i=0;i<n-1;i++) {
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    //Array to mark visited nodes
    bool visited[n+1];
    memset(visited,false,sizeof visited);

    //Call first time depth first search to find
    //the max node we can reach from start
    dfs(vec,visited,1,0);

    //Make visited again false for second pass
    memset(visited,false,sizeof visited);

    //In second pass start from max node and find the
    //length of maximum path
    dfs(vec,visited,maxNode,0);

    //print the maximum path
    cout<<maxLen<<endl;
}
