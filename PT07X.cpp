#include<bits/stdc++.h>

using namespace std;

#define MAX 100005

//DP to store state of selected or not
int dp[MAX][2];

//Recurse the tree
void recurse(vector< vector<int> > &vec,int cur,int p) {

    //Traverse all children first to store the results first
    for(int i=0;i<vec[cur].size();i++) {
        if(vec[cur][i] != p)
            recurse(vec,vec[cur][i],cur);
    }

    //Now traverse each child
    for(int i=0;i<vec[cur].size();i++) {
        if(vec[cur][i] != p) {

            //IF we select current node then we can choose between
            //minimum of child selected or not
            dp[cur][0] += min(dp[vec[cur][i]][0],dp[vec[cur][i]][1]);

            //If we cant choose this node then we have to choose selected
            //children
            dp[cur][1] += dp[vec[cur][i]][0];
        }
    }

    //Mark current node as selected
    dp[cur][0]++;
}

int main() {

    //Take number of nodes
    int n,a,b,res=0,e = 0;
    cin>>n;

    //Take input
    vector< vector<int> > vec(n);
    for(int i=0;i<n-1;i++) {
        cin>>a>>b;
        vec[a-1].push_back(b-1);
        vec[b-1].push_back(a-1);
    }

    //Recurse
    recurse(vec,0,0);

    //Print minimum of selected or not selected root node
    cout<<min(dp[0][0],dp[0][1])<<endl;
}
