#include<bits/stdc++.h>

using namespace std;

#define MAX 1005

int level[MAX],parent[MAX],P[MAX];

//Traverse the tree to find parent and level of each node
void traverse(vector< vector<int> > &vec,int node,int p,int l) {

    parent[node] = p;
    level[node] = l;
    for(int i=0;i<vec[node].size();i++) {
        if(vec[node][i] != p)
            traverse(vec,vec[node][i],node,l+1);
    }
}

// Pre compute the P table of storing parent sqrt block lower element
//all tree height is divided into sqrt blocks
void precompute(vector< vector<int> > &vec,int node,int head,int prev_sec) {

    //Find the current section
    int cur_sec = sqrt(level[node]) + 1;

    //If this is first section make it 1
    if(cur_sec == 1) {
        P[node] = 1;
    } else {

        //If current section is new mark current node as head
        //of this section and store parent
        if(cur_sec == prev_sec + 1) {
            P[node] = parent[node];
            head = node;
        } else {

            //If this is same section mark the parent as parent of head
            //of this section
            P[node] = parent[head];
        }
    }

    //Go for child nodes
    for(int i=0;i<vec[node].size();i++) {
        if(vec[node][i] != parent[node])
            precompute(vec,vec[node][i],head,cur_sec);
    }
}

//Find lowest common ancestor of a and b
int lca(int a,int b) {

    //First make their section equals
    while(P[a] != P[b]) {
        if(level[a] < level[b])
            b = P[b];
        else
            a = P[a];
    }

    //Now go parent by parent and make them equal
    while(a != b) {
        if(level[a] > level[b])
            a = parent[a];
        else
            b = parent[b];
    }
    return a;
}

int main() {

    //Take number of test cases
    int t,n,num,tmp,q,a,b;
    cin>>t;

    //Loop over all test cases
    for(int k=0;k<t;k++) {
        cin>>n;

        //Take input and store
        vector< vector<int> > vec(n);
        memset(level,0,sizeof(level));
        memset(parent,0,sizeof(parent));
        memset(P,0,sizeof(P));

        for(int i=0;i<n;i++){
            cin>>num;
            for(int j=0;j<num;j++){
                cin>>tmp;
                vec[i].push_back(tmp - 1);
            }
        }

        //Traverse once to find parent and level
        traverse(vec,0,0,0);

        //Precompute P table
        precompute(vec,0,0,0);

        //Print the answer according to queries
        cout<<"Case "<<k+1<<":"<<endl;
        cin>>q;
        for(int i=0;i<q;i++){
            cin>>a>>b;
            cout<<lca(a-1,b-1)+1<<endl;
        }
    }
}
