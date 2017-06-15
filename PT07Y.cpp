#include<bits/stdc++.h>

using namespace std;

//To find parent of current node
int findP(int parent[],int i) {
    if(parent[i] == -1)
        return i;
    return findP(parent,parent[i]);
}

//Union two nodes
void unionNode(int parent[],int x,int y) {
    parent[x] = y;
}

int main() {

    //Take number of nodes and edges
    int n,e;
    cin>>n>>e;

    //Check if it contains number of nodes
    //one grater than edges for tree property
    if(n != e+1) {
        cout<<"NO"<<endl;
        return 0;
    }

    //Make a parent array which contains parent of every node
    int parent[n+1];
    memset(parent,-1,sizeof(parent));

    int u,v;
    for(int i=0;i<e;i++) {

        //Take current edges
        cin>>u>>v;

        //Find parent of both
        int xP = findP(parent,u);
        int yP = findP(parent,v);

        //check if parent of both are equal
        //if yes then this will create a cycle
        if(xP  == yP) {
            cout<<"NO"<<endl;
            return 0;
        }

        //else make parent of these nodes equal
        unionNode(parent,xP,yP);
    }

    //Print yes if all conditions are met
    cout<<"YES"<<endl;
    return 0;
}
