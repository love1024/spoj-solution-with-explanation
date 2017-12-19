#include<bits/stdc++.h>

using namespace std;

#define MAX 10005

//To store edge
class Edge {
public:
    int u,v,w;
    Edge(int u,int v,int w):u(u),v(v),w(w) {}
    Edge(){}
};

//Store Node for union set
class Node {
public:
    int val,w;
    Node(int val,int w):val(val),w(w){}
    Node() {}
};

//Union set array
Node arr[MAX];

//Compare two edges
bool compare(Edge &a,Edge &b) {
    return a.w < b.w;
}

//Find parent of a node
int findParent(int i) {
    if(arr[i].val == i)
        return i;
    return findParent(arr[i].val);
}

//Merge two nodes
bool mergeNode(int a,int b) {
    int ap = findParent(a);
    int bp = findParent(b);

    if(ap == bp)
        return false;

    if(arr[ap].w > arr[bp].w) {
        arr[bp].val = arr[ap].val;
        arr[ap].w = arr[ap].w + arr[bp].w;
    } else {
        arr[ap].val = arr[bp].val;
        arr[bp].w = arr[bp].w + arr[ap].w;
    }

    return true;
}

//Minimum spanning tree
int main() {

    //Take number of test cases
    int t,n,c,u,w;
    string str;
    cin>>t;

    //Loop over all test cases
    while(t--) {

        //Take number of nodes
        cin>>n;

        //Initialize node
        for(int i=0;i<=n;i++) {
            arr[i] = Node(i,1);
        }

        // Take all edges
        vector<Edge> edges;
        for(int i=0;i<n;i++) {
            cin>>str>>c;
            for(int j=0;j<c;j++) {
                cin>>u>>w;
                edges.push_back(Edge(i+1,u,w));
            }
        }

        //Sort edges
        sort(edges.begin(),edges.end(),compare);

        //Now try to add edges and check if cycle
        //can form
        long long cost = 0;
        for(int i=0;i<edges.size();i++) {
            if(mergeNode(edges[i].u,edges[i].v))
                cost += edges[i].w;
        }

        //Print cost
        cout<<cost<<endl;
    }
}
