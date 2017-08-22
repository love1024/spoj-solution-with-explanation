#include<bits/stdc++.h>

using namespace std;

//Edge of the graph
//Consist of starting and ending and cost of edge
class Edge {
public:
    int u,v,c;
    Edge(int u,int v,int c) {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

//Node of the disjoint set
//consist and parent and rank or size of parent
class Node {
public:
    int p,r;
    Node(int p,int r) {
        this->p = p;
        this->r = r;
    }
};

//Function to compare two edges
bool compare(Edge &a,Edge &b) {
    return a.c < b.c;
}

//Find the parent of node in disjoint set
int fnd(vector<Node> &p,int i) {
    if(p[i].p == i)
        return i;
    return fnd(p,p[i].p);
}

//merge two sets using union rank algorithm
bool add(vector<Node> &par,int x,int y) {

    //Find parent of both sets
    int p1 = fnd(par,x);
    int p2 = fnd(par,y);

    //If parent of two nodes are equal
    //Then this will form cycle return false
    if(p1 == p2)
        return false;

    //else if size of first is small add second set
    //to it
    else if(par[p1].r > par[p2].r) {

        //Make first the parent of second
        par[p2].p = p1;

        //Add size of second in firsts
        par[p1].r += par[p2].r;
    } else  {

        //Else same procedure for first rank
        par[p1].p = p2;
        par[p2].r += par[p1].r;
    }
    return true;
}

//KRUSKEL ALGORITHM
int main() {

    //Take the variables
    int t,p,n,m,a,b,c;
    cin>>t;

    //Loop over all test cases
    while(t--) {
        cin>>p>>n>>m;

        //Graph and disjoint set
        vector<Edge> graph;
        vector<Node> uni;

        //Initialize the disjoint set
        for(int i=0;i<n;i++) {
            uni.push_back(Node(i,1));
        }

        //Take the edges
        for(int i=0;i<m;i++) {
            cin>>a>>b>>c;
            graph.push_back(Edge(a,b,c*p));
        }

        //Sort the edges
        sort(graph.begin(),graph.end(),compare);

        //If we can add edge the add its cost
        long cst = 0;
        for(int i=0;i<m;i++) {
            Edge cur = graph[i];
            if(add(uni,cur.u-1,cur.v-1)) {
                cst += cur.c;
            }
        }

        //Print the cost
        cout<<cst<<endl;
    }
}
